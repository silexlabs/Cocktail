package core.ds;

import buddy.*;
using buddy.Should;

import cocktail.core.ds.FastNode;

class FastNodeTest extends BuddySuite {

    public function new()
    {
        describe('Fast Node', function () {
            describe('#removeChild', function () {
                it('should remove an existing child', function () {
                    var parentNode = new TestNode();
                    var childNode = new TestNode();
                    parentNode.appendChild(childNode);

                    parentNode.firstChild.should.be(childNode);

                    parentNode.removeChild(childNode);
                    childNode.parentNode.should.be(null);
                    parentNode.firstChild.should.be(null);
                });
                it('should throw if not a child', function () {
                    var parentNode = new TestNode();
                    var anotherNode = new TestNode();

                    parentNode.removeChild.bind(anotherNode)
                    .should.throwValue('not a child node');
                });
            });

            describe('#appendChild', function () {
                it('should add a child', function () {
                    var parentNode = new TestNode();
                    var childNode = new TestNode();
                    parentNode.appendChild(childNode);

                    parentNode.firstChild.should.be(childNode);
                    parentNode.lastChild.should.be(childNode);
                    childNode.parentNode.should.be(parentNode);
                });
            });

            describe('#insertBefore', function () {
                it('should insert the child before another one', function () {
                    var parentNode = new TestNode();
                    var firstChildNode = new TestNode();
                    var childNode = new TestNode();
                    
                    parentNode.appendChild(firstChildNode);
                    parentNode.insertBefore(childNode, firstChildNode);

                    parentNode.firstChild.should.be(childNode);
                    childNode.parentNode.should.be(parentNode);
                    childNode.nextSibling.should.be(firstChildNode);
                    childNode.previousSibling.should.be(null);
                    parentNode.lastChild.should.be(firstChildNode);
                    firstChildNode.parentNode.should.be(parentNode);
                    firstChildNode.nextSibling.should.be(null);
                    firstChildNode.previousSibling.should.be(childNode);
                });

                it('should throw if ref node is not a child', function () {
                    var parentNode = new TestNode();
                    var childNode = new TestNode();
                    var anotherNode = new TestNode();

                    parentNode.insertBefore.bind(childNode, anotherNode)
                    .should.throwValue('not a child node');
                });
            });
        });
    }
}

class TestNode extends FastNode<TestNode> implements IFastNode<TestNode>
{
    public function new()
    {
        super();
    }
}
