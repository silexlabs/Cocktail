package core.boxmodel;

import haxe.ds.Option;

import buddy.*;
using buddy.Should;
import utest.*;

import cocktail.core.boxmodel2.BoxModel;

class BoxModelTest extends BuddySuite {

    public function new() {
        describe('BoxModel', function () {
            describe('getComputedPadding', function () {
                it('computes absolute length padding', function () {
                    BoxModel.getComputedPadding(AbsoluteLength(50), 100)
                    .should.be(50);
                });

                it('computes percent padding', function () {
                    BoxModel.getComputedPadding(Percent(20), 100)
                    .should.be(20);
                });
            });

            describe('getComputedConstrainedDimension', function () {
                it('computes absolute length constraint', function () {
                    var ret = BoxModel.getComputedConstrainedDimension(AbsoluteLength(50), 100, false);
                    Assert.same(Some(50), ret);
                });

                describe('percent constraint', function () {
                    it('computes percent constraint', function () {
                        var ret = BoxModel.getComputedConstrainedDimension(Percent(20), 100, false);
                        Assert.same(ret, Some(20));
                    });

                    it('uses empty value if container is auto', function () {
                        var ret:Option<Int> = BoxModel.getComputedConstrainedDimension(Percent(50), 100, true);
                        Assert.same(None, ret);

                        var ret2:Option<Int> = BoxModel.getComputedConstrainedDimension(Percent(50), 100, true);
                        Assert.same(None, ret2);
                    });

                    it('uses empty value if there are no constraints', function () {
                        var ret = BoxModel.getComputedConstrainedDimension(Unconstrained, 100, true);
                        Assert.same(ret, None);
                    });
                });
            });
        });
    }
}
