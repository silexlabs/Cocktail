package core.boxmodel;

import haxe.ds.Option;

import buddy.*;
using buddy.Should;
import utest.*;

import cocktail.core.boxmodel2.BoxModel;

class BoxModelTest extends BuddySuite {

    public function new() {
        describe('BoxModel', function () {
            describe('getPadding', function () {
                it('computes absolute length padding', function () {
                    BoxModel.getPadding(AbsoluteLength(50), 100)
                    .should.be(50);
                });

                it('computes percent padding', function () {
                    BoxModel.getPadding(Percent(20), 100)
                    .should.be(20);
                });
            });

            describe('getConstraint', function () {
                it('computes absolute length constraint', function () {
                    var ret = BoxModel.getConstraint(AbsoluteLength(50), 100, false);
                    Assert.same(Some(50), ret);
                });

                describe('percent constraint', function () {
                    it('computes percent constraint', function () {
                        var ret = BoxModel.getConstraint(Percent(20), 100, false);
                        Assert.same(ret, Some(20));
                    });

                    it('uses empty value if container is auto', function () {
                        var ret:Option<Int> = BoxModel.getConstraint(Percent(50), 100, true);
                        Assert.same(None, ret);

                        var ret2:Option<Int> = BoxModel.getConstraint(Percent(50), 100, true);
                        Assert.same(None, ret2);
                    });

                    it('uses empty value if there are no constraints', function () {
                        var ret = BoxModel.getConstraint(Unconstrained, 100, true);
                        Assert.same(ret, None);
                    });
                });
            });

            describe('constrainDimension', function () {
              it('constraints a dimension to its max', function () {
                BoxModel.constrainDimension(200, Some(100), None)
                .should.be(100);
              });

              it('constraints a dimension to its min', function () {
                BoxModel.constrainDimension(100, None, Some(200))
                .should.be(200);
              });
            });

            describe('getBlockMargin', function () {
              describe('Percent', function () {
                it('has no margin if width is auto', function () {
                  BoxModel.getBlockMargin(Percent(50), Auto, 100, 50, true, 50, true)
                  .should.be(0);
                });
              });
            });

            describe('getAutoHorizontalMargin', function () {
              it('takes half the remaining container space if the opposite margin is auto', function () {
                BoxModel.getAutoHorizontalMargin(Auto, 200, 100, 50)
                .should.be(25);
              });

              it('takes the remaining container space after the opposite margin value is known', function () {
                BoxModel.getAutoHorizontalMargin(AbsoluteLength(20), 200, 100, 50)
                .should.be(30);
              });
            });

            describe('getInlineMargin', function () {
              it('has no margin if auto', function () {
                BoxModel.getInlineMargin(Auto, 100, true)
                .should.be(0);
              });
            });

            describe('getHeight', function () {
                it('is 0 for inline boxes', function () {
                    BoxModel.getHeight(Auto, {
                        minHeight: None, minWidth: None, maxHeight: None, maxWidth: None
                    }, {
                        height: 10, width: 10, isHeightAuto: true, isWidthAuto: true
                    }, true)
                    .should.be(0);
                });
            });

            describe('getWidth', function () {
                it('is 0 for auto floated boxes', function () {
                    BoxModel.getWidth(Auto, {
                        left: 10, right: 10, top: 10, bottom: 10
                    }, {
                        left: 10, right: 10, top: 10, bottom: 10
                    }, {
                        left: 10, right: 10, top: 10, bottom: 10
                    }, {
                        minWidth: None, minHeight: None, maxWidth: None, maxHeight: None
                    }, {
                        width: 10, height: 10, isHeightAuto: true, isWidthAuto: true
                    }, true, false)
                    .should.be(0);
                });

                it('is 0 for inline boxes', function () {
                    BoxModel.getWidth(Auto, {
                        left: 10, right: 10, top: 10, bottom: 10
                    }, {
                        left: 10, right: 10, top: 10, bottom: 10
                    }, {
                        left: 10, right: 10, top: 10, bottom: 10
                    }, {
                        minWidth: None, minHeight: None, maxWidth: None, maxHeight: None
                    }, {
                        width: 10, height: 10, isHeightAuto: true, isWidthAuto: true
                    }, false, true)
                    .should.be(0);
                });
            });

            describe('getAutoWidth', function () {
              it('takes the remaining container space left by the box model', function () {
                BoxModel.getAutoWidth({
                  left: 10, right: 10, top: 0, bottom: 0
                }, {
                  left: 10, right: 10, top: 0, bottom: 0
                }, 10, 10, {
                  width: 100, height: 0, isHeightAuto: false, isWidthAuto: false
                }).should.be(40);
              });
            });
        });
    }
}
