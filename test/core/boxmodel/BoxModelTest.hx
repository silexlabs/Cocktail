package core.boxmodel;

import buddy.*;
using buddy.Should;

import cocktail.core.boxmodel2.BoxModel;

class BoxModelTest extends BuddySuite {

    public function new()
    {
        describe('BoxModel', function () {
            describe('#measure', function () {
                it('should return the computed layout styles for a node', function () {
                });
            });

            describe('getComputedPadding', function () {
                it('should compute absolute length padding', function () {
                    BoxModel.getComputedPadding(AbsoluteLength(50), 100)
                    .should.be(50);
                });

                it('should compute percent padding', function () {
                    BoxModel.getComputedPadding(Percent(20), 100)
                    .should.be(20);
                });
            });
        });
    }
}
