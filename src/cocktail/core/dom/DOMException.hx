/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.dom;

/**
 * DOM operations only raise exceptions in "exceptional" circumstances, i.e.,
 * when an operation is impossible to perform (either for logical reasons,
 * because data is lost, or because the implementation has become unstable).
 * In general, DOM methods return specific error values in ordinary
 * processing situations, such as out-of-bound errors 
 * when using NodeList.
 * 
 * @author Yannick DOMINGUEZ
 */
class DOMException 
{
	/**
	 * If index or size is negative, or greater than the allowed value.
	 */
	public static inline var INDEX_SIZE_ERR:Int = 1;
	
	/**
	 * If the specified range of text does not fit into a DOMString.
	 */
	public static inline var DOMSTRING_SIZE_ERR:Int = 2;
	
	/**
	 * If any Node is inserted somewhere it doesn't belong.
	 */
	public static inline var HIERARCHY_REQUEST_ERR:Int = 3;
	
	/**
	 * If a Node is used in a different document than
	 * the one that created it (that doesn't support it).
	 */
	public static inline var WRONG_DOCUMENT_ERR:Int = 4;
	
	/**
	 * If an invalid or illegal character is specified, such as in an XML name.
	 */
	public static inline var INVALID_CHARACTER_ERR:Int = 5;
	
	/**
	 * If data is specified for a Node which does not support data.
	 */
	public static inline var NO_DATA_ALLOWED_ERR:Int = 6;
	
	/**
	 * If an attempt is made to modify an object where modifications are not allowed.
	 */
	public static inline var NO_MODIFICATION_ALLOWED_ERR:Int = 7;
	
	/**
	 * If an attempt is made to reference a Node in a context where it does not exist.
	 */
	public static inline var NOT_FOUND_ERR:Int = 8;
	
	/**
	 * If the implementation does not support the requested type of object or operation.
	 */
	public static inline var NOT_SUPPORTED_ERR:Int = 9;
	
	/**
	 * If an attempt is made to add an attribute that is already in use elsewhere.
	 */
	public static inline var INUSE_ATTRIBUTE_ERR:Int = 10;
	
	/**
	 * If an attempt is made to use an object that is not, or is no longer, usable.
	 */
	public static inline var INVALID_STATE_ERR:Int = 11;
	
	/**
	 * If an invalid or illegal string is specified.
	 */
	public static inline var SYNTAX_ERR:Int = 12;
	
	/**
	 * If an attempt is made to modify the type of the underlying object.
	 */
	public static inline var INVALID_MODIFICATION_ERR:Int = 13;
	
	/**
	 * If an attempt is made to create or change an object in a way which is 
	 * incorrect with regard to namespaces.
	 */
	public static inline var NAMESPACE_ERR:Int = 14;
	
	/**
	 * If a parameter or an operation is not supported by the underlying object.
	 */
	public static inline var INVALID_ACCESS_ERR:Int = 15;
	
	/**
	 * If a call to a method such as insertBefore or removeChild would make the Node
	 * invalid with respect to "partial validity",
	 * this exception would be raised and the operation would not be done.
	 */
	public static inline var VALIDATION_ERR:Int = 16;
	
	/**
	 * If the type of an object is incompatible with the expected type of the parameter associated to the object. 
	 */
	public static inline var TYPE_MISMATCH_ERR:Int = 19;
	
	/**
	 * class constructor. Private as only
	 * static exception code are meant
	 * to be used on this class
	 */
	private function new() 
	{
		
	}
	
}