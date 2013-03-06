package cocktail.core.utils;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class FastNode<NodeClass:FastNode<NodeClass>>
{
	public var parentNode:NodeClass;

	public var firstChild:NodeClass;
	
	public var lastChild:NodeClass;
	
	public var nextSibling:NodeClass;
	
	public var previousSibling:NodeClass;
	
	public function new() 
	{
		
	}
	
	public function removeChild(oldChild:NodeClass):Void
	{
		oldChild.parentNode = null;
		
		if (firstChild == oldChild && lastChild == oldChild)
		{
			firstChild = null;
			lastChild = null;
		}
		else if (firstChild == oldChild)
		{
			var nextSibling = oldChild.nextSibling;
			firstChild = nextSibling;
			if (nextSibling != null)
			{
				nextSibling.previousSibling = null;
			}
		}
		else if (lastChild == oldChild)
		{
			var previousSibling = oldChild.previousSibling;
			lastChild = previousSibling;
			if (previousSibling != null)
			{
				previousSibling.nextSibling = null;
			}
		}
		else
		{
			var previousSibling = oldChild.previousSibling;
			var nextSibling = oldChild.nextSibling;
			
			previousSibling.nextSibling = nextSibling;
			nextSibling.previousSibling = previousSibling;
		}
		
		oldChild.previousSibling = null;
		oldChild.nextSibling = null;
	}
	
	public function appendChild(newChild:NodeClass):Void
	{
		removeFromParentIfNecessary(newChild);
		newChild.parentNode = cast(this);
		
		if (firstChild == null)
		{
			firstChild = newChild;
			lastChild = newChild;
			newChild.previousSibling = null;
			newChild.nextSibling = null;
		}
		else
		{
			var oldLastChild = lastChild;
			lastChild = newChild;
			oldLastChild.nextSibling = newChild;
			newChild.previousSibling = oldLastChild;
			newChild.nextSibling = null;
		}
	}
	
	private function removeFromParentIfNecessary(newChild:NodeClass):Void
	{
		if (newChild.parentNode != null)
		{
			var parentNode:NodeClass = newChild.parentNode;
			parentNode.removeChild(newChild);
		}
	}
	
	public function insertBefore(newChild:NodeClass, refChild:NodeClass):Void
	{
		if (firstChild == null || refChild == null)
		{
			appendChild(newChild);
			return;
		}
		
		removeFromParentIfNecessary(newChild);
		newChild.parentNode = cast(this);
		
		var oldPreviousSibling = refChild.previousSibling;
		if (oldPreviousSibling == null)
		{
			firstChild = newChild;
			refChild.previousSibling = newChild;
			newChild.nextSibling = refChild;
			newChild.previousSibling = null;
		}
		else
		{
			oldPreviousSibling.nextSibling = newChild;
			refChild.previousSibling = newChild;
			
			newChild.previousSibling = oldPreviousSibling;
			newChild.nextSibling = refChild;
		}
	}
	
}