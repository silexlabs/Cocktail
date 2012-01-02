/**
 * This class defines an imageDOMElement with a thumbnail
 * 
 * @author Raphael Harmel
 */

package components.gallery;

import cocktail.domElement.ImageDOMElement;
import cocktail.nativeElement.NativeElement;


class ImageThumbDOMElement extends ImageDOMElement
{
	public var fullImagePath:String;
	
	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
	
}