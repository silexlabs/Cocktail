package core.event;

import buddy.*;
using buddy.Should;

import cocktail.core.event.*;

class EventTargetTest extends BuddySuite {

    public function new()
    {
        describe('Event Target', function () {

            describe('#dispatchEvent', function () {
                var eventTarget, event;
                before(function () {
                    eventTarget = new EventTarget();
                    event = new Event();
                    event.initEvent('test', false, false);
                });

                it('should set the event to dispatched', function () {
                    event.dispatched.should.be(false);
                    eventTarget.dispatchEvent(event);
                    event.dispatched.should.be(true);
                });
                it('should set the event current target and target', function () {
                    event.target.should.be(null);
                    event.currentTarget.should.be(null);
                    eventTarget.dispatchEvent(event);
                    event.target.should.be(eventTarget);
                    event.currentTarget.should.be(eventTarget);
                });
                it('should set the event phases', function () {
                    event.eventPhase.should.be(0);
                    eventTarget.dispatchEvent(event);
                    event.eventPhase.should.be(2);
                });
            });

            describe('#addEventListener', function () {
                var eventTarget, event, listener, count;
                before(function () {
                    eventTarget = new EventTarget();
                    event = new Event();
                    event.initEvent('test', false, false);
                    count = 0;
                    listener = function (e) count++;
                });

                it('should add listeners called when dispatching', function () {
                    eventTarget.addEventListener('test', listener);
                    eventTarget.dispatchEvent(event);

                    var otherEvent = new Event();
                    otherEvent.initEvent('otherType', false, false);
                    eventTarget.dispatchEvent(otherEvent);

                    count.should.be(1);
                });
            });

            describe('#removeEventListener', function () {
                var eventTarget, event, listener, count;
                before(function () {
                    eventTarget = new EventTarget();
                    event = new Event();
                    event.initEvent('test', false, false);
                    count = 0;
                    listener = function (e) count++;
                });

                it('should remove a previously added event listener', function () {
                    eventTarget.addEventListener('test', listener);
                    eventTarget.dispatchEvent(event);

                    eventTarget.removeEventListener('test', listener);
                    eventTarget.dispatchEvent(event);
                    count.should.be(1);
                });

            });
        });
    }
}

