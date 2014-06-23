/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.css;

import cocktail.css.CSSStyleData;
import cocktail.geom.GeomData;
import cocktail.geom.Matrix;

/**
  * Represents the used values of an HTMLElement, that is
  * the value which will be used during layout. For instance,
  * during layout, width or height are represented by a
  * floating number
  */
class UsedValuesVO {
    public var width:Float;
    public var minHeight:Float;
    public var maxHeight:Float;
    public var minWidth:Float;
    public var maxWidth:Float;
    public var height:Float;
    public var marginLeft:Float;
    public var marginRight:Float;
    public var marginTop:Float;
    public var marginBottom:Float;
    public var paddingLeft:Float;
    public var paddingRight:Float;
    public var paddingTop:Float;
    public var paddingBottom:Float;
    public var left:Float;
    public var right:Float;
    public var top:Float;
    public var bottom:Float;
    public var textIndent:Float;
    public var color:ColorVO;
    public var lineHeight:Float;
    public var letterSpacing:Float;
    public var transformOrigin:PointVO;
    public var transform:Matrix;
    public var backgroundColor:ColorVO;
    public var borderLeftWidth:Float;
    public var borderRightWidth:Float;
    public var borderTopWidth:Float;
    public var borderBottomWidth:Float;
    public var borderTopColor:ColorVO;
    public var borderRightColor:ColorVO;
    public var borderBottomColor:ColorVO;
    public var borderLeftColor:ColorVO;
    public var outlineWidth:Float;
    public var outlineColor:ColorVO;

    public function new()
    {
        minHeight = 0.0;
        maxHeight = 0.0;
        minWidth = 0.0;
        maxWidth = 0.0;
        width = 0.0;
        height = 0.0;
        marginLeft = 0.0;
        marginRight = 0.0;
        marginTop = 0.0;
        marginBottom = 0.0;
        paddingLeft = 0.0;
        paddingRight = 0.0;
        paddingTop = 0.0;
        paddingBottom = 0.0;
        left = 0.0;
        right = 0.0;
        top = 0.0;
        bottom = 0.0;
        textIndent = 0;
        lineHeight = 0.0;
        letterSpacing = 0.0;
        color = new ColorVO(0, 1.0);
        transformOrigin = new PointVO(0.0, 0.0);
        transform = new Matrix();
        backgroundColor = new ColorVO(0, 0.0);
        borderLeftWidth = 0.0;
        borderRightWidth = 0.0;
        borderTopWidth = 0.0;
        borderBottomWidth = 0.0;
        borderLeftColor = new ColorVO(0, 1.0);
        borderRightColor = new ColorVO(0, 1.0);
        borderTopColor = new ColorVO(0, 1.0);
        borderBottomColor = new ColorVO(0, 1.0);
        outlineWidth = 0.0;
        outlineColor = new ColorVO(0, 1.0);

    }
}
