/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.event;

/**
 * Allows registration and removal 
 * of event listeners, and dispatch of events to an event target.
 * 
 * @author Yannick DOMINGUEZ
 */
class EventTarget
{
	/**
	 * store the registered eventListeners in a hash
	 * where the key is the event type. Each key
	 * returns an array of the EventListeners registered
	 * for this type of event, in the order where
	 * they were registered
	 */
	private var _registeredEventListeners:Map<String, Array<EventListener>>;
	
	/**
	 * When dispatching an event, 
	 * holds all the parent
	 * ancestors
	 */
	private var _targetAncestors:Array<EventTarget>;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Dispatches an event into the implementation's event model.
	 * The event target of the event must be the EventTarget object on which dispatchEvent is called.
	 * 
	 * @param	evt The event to be dispatched.
	 * @return Indicates whether any of the listeners which handled the event called Event.preventDefault().
	 * If Event.preventDefault() was called the is false
	 */
	public function dispatchEvent(evt:Event):Bool
	{
		//the currentTarget because this EventTarget, as 
		//it is now going to deal with its own registered
		//EventListeners
		evt.currentTarget = this;
		
		//this flag allow distinguishing between the EventTarget on 
		//which the dispatchEvent method was first called and its ancestors,
		//whose dispatchEvent method are called after
		if (evt.dispatched == false)
		{
			//This EventTarget becomes the target of the event as dispatchEvent
			//was called on it
			evt.target = this;
			
			//set the flag so that next EventTarget knows they are ancestor
			//of the event target
			evt.dispatched = true;
			
			//retrieve all the target ancestor. For instance, for a Node,
			//returns all ancestors from the Node to the root of the document
			var targetAncestors:Array<EventTarget> = getTargetAncestors();

			//the capturing phase of the event flow begins
			evt.eventPhase = Event.CAPTURING_PHASE;

			//reverse the target ancestors, as during capture phase, 
			//the first ancestor whose dispatchEvent should be called is
			//the root of the document
			targetAncestors.reverse();
			
			//make all target ancestor dispatch their events
			var length:Int = targetAncestors.length;
			for (i in 0...length)
			{
				targetAncestors[i].dispatchEvent(evt);
				//if the previous target ancestor stopped propagation, stop
				//the event flow
				if (shouldStopEventPropagation(evt) == true)
				{
					//end the event dispatching by executing default
					//behaviour if needed
					return endEventDispatching(evt);
				}
			}
			
			//the target phase begins, as the event target will now dispatch itself
			evt.eventPhase = Event.AT_TARGET;
			dispatchEvent(evt);
			
			//return if propagation must be stopped
			if (shouldStopEventPropagation(evt) == true)
			{
				return endEventDispatching(evt);
			}
			
			//check if the event supports the bubbling phase
			if (evt.bubbles == true)
			{
				//start the bubbling phase
				evt.eventPhase = Event.BUBBLING_PHASE;
				
				//reverse the array again, as the bubbling phase starts with
				//the parent of the event target and finish with the root
				//of the document
				targetAncestors.reverse();
				
				//dispatch all target ancestor, and stop propagation if needed
				var length:Int = targetAncestors.length;
				for (i in 0...length)
				{
					targetAncestors[i].dispatchEvent(evt);
					
					if (shouldStopEventPropagation(evt) == true)
					{
						return endEventDispatching(evt);
					}
				}
				
				//finish event dispatching, call the default actions
				return endEventDispatching(evt);
			}
		}
		//this part is executed for target ancestor and for the target
		//itself at AT_TARGET phase
		else
		{
			if (_registeredEventListeners != null)
			{
				var eventRegisteredForEventType:Null<Array<EventListener>> = _registeredEventListeners.get(evt.type);
				//tries to dispatch event registered for the event type
				if (eventRegisteredForEventType != null)
				{
					doDispatchEvent(eventRegisteredForEventType, evt);
				}
			}
		}
		
		//return wether any EventListener called event.preventDefault
		//during event flow
		return evt.defaultPrevented;
	}

	/**
	 * Registers an event listener, depending on the useCapture parameter,
	 * on the capture phase of the DOM event flow or its target and bubbling phases. 
	 * 
	 * @param	type Specifies the Event.type associated with the event for which the user is registering.
	 * @param	listener 
	 * The listener parameter must be an object which implements the EventListener
	 * interface, such as a reference to a . 
	 * 
	 * The listener parameter must be either an object
	 * that implements the EventListener interface, or a function.
	 * If listener is a function then it must be used as the callback
	 * for the event; otherwise, if listener implements EventTarget,
	 * then its handleEvent method must be used as the callback.
	 * 
	 * The listener parameter takes an object defined by the author
	 * which implements the EventListener interface and contains the method
	 * to be called when the event occurs.
	 * 
	 * @param	useCapture If true, useCapture indicates that the user wishes
	 * to add the event listener for the capture and target phases 
	 * only, i.e., this event listener will not be triggered during the bubbling
	 * phase. If false, the event listener must only be triggered during
	 * the target and bubbling phases.
	 */
	public function addEventListener(type:String, listener:Dynamic->Void, useCapture:Bool = false):Void
	{
		if (_registeredEventListeners == null)
		{
			_registeredEventListeners = new Map<String, Array<EventListener>>();
		}
		
		if (_registeredEventListeners.exists(type) == false)
		{
			_registeredEventListeners.set(type, new Array<EventListener>());
		}
		
		var eventListener:EventListener = new EventListener(type, listener, useCapture);
		
		_registeredEventListeners.get(type).push(eventListener);
	}

	/**
	 * Removes an event listener. Calling removeEventListener with arguments
	 * which do not identify any currently registered EventListener on the EventTarget has no effect. 
	 * 
	 * @param	type Specifies the Event.type for which the user registered the event listener.
	 * @param	listener The EventListener to be removed.
	 * @param	useCapture 
	 * Specifies whether the EventListener being removed was registered for the capture
	 * phase or not. If a listener was registered twice, once for the capture and
	 * target phases and once for the target and bubbling phases, each must be removed 
	 * separately. Removal of an event listener registered for the capture and target
	 * phases does not affect the same event listener registered for the target and bubbling phases,
	 * and vice versa.
	 */
	public function removeEventListener(type:String, listener:Dynamic->Void, useCapture:Bool = false):Void
	{
		//no event listener was added yet
		if (_registeredEventListeners == null)
		{
			return;
		}
		
		var registeredEventListenersForType:Array<EventListener> = _registeredEventListeners.get(type);
		if (registeredEventListenersForType != null)
		{
			var newEventListeners:Array<EventListener> = new Array<EventListener>();
			
			var length:Int = registeredEventListenersForType.length;
			for (i in 0...length)
			{
				var eventListener:EventListener = registeredEventListenersForType[i];
				
				if (eventListener.eventType != type || eventListener.useCapture != useCapture || eventListener.listener != listener)
				{
					newEventListeners.push(eventListener);
				}
			}
			
			_registeredEventListeners.set(type, newEventListeners);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Tries to dispatch the registered events listener for the  given
	 * event type
	 */
	private function doDispatchEvent(eventListeners:Array<EventListener>, evt:Event):Void
	{
		var length:Int = eventListeners.length;
		for (i in 0...length)
		{
			var eventListener:EventListener = eventListeners[i];
			
			//check if the current phase matches the eventListener
			//registered for phase
	
			//for capturing phase
			if (evt.eventPhase == Event.CAPTURING_PHASE)
			{
				if (eventListener.useCapture == true)
				{
					eventListener.handleEvent(evt);
				}
			}
			//for bubbling phase
			else if (evt.eventPhase == Event.BUBBLING_PHASE)
			{
				if (eventListener.useCapture == false)
				{
					eventListener.handleEvent(evt);
				}
			}
			//at "at target" phase, all the eventListeners are
			//executed
			else if (evt.eventPhase == Event.AT_TARGET)
			{
				eventListener.handleEvent(evt);
			}
			
			//stop the event flow if the eventListener stopped
			//immediate propagetion (called Event.stopImmediatePropagation)
			//If an EventListener calls Event.stopPropagation, all the
			//EventListener of the current target are executed
			if (evt.immediatePropagationStopped == true)
			{
				return;
			}
		}
	}
	
	/**
	 * Utils method determining if event propagation
	 * should be stopped
	 */
	private function shouldStopEventPropagation(evt:Event):Bool
	{
		return evt.propagationStopped == true || evt.immediatePropagationStopped == true;
	}
	
	/**
	 * End the dispatching of an event
	 */
	private function endEventDispatching(evt:Event):Bool
	{
		var defaultPrevented:Bool = evt.defaultPrevented;
		executeDefaultActionIfNeeded(defaultPrevented, evt);
		return defaultPrevented;
	}
	
	/**
	 * Return all the EventTarget ancestors of this EventTarget,
	 * filling the arrayimplemented by inheriting classes
	 */
	private function getTargetAncestors():Array<EventTarget>
	{
		_targetAncestors = new Array<EventTarget>();
		return _targetAncestors;
	}
	
	/**
	 * If the EventTarget is associated to a default action, execute
	 * if it wasn't prevented during the event flow
	 */
	private function executeDefaultActionIfNeeded(defaultPrevented:Bool, event:Event):Void
	{
		//abstract
	}
	
}