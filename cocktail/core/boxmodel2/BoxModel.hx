package cocktail.core.boxmodel2;

import haxe.ds.Option;

class BoxModel {

  public static function measure(node:StyleNode, containingBlock:ContainingBlock):UsedStyleNode {
    return {
      paddings: measurePaddings(node.paddings, containingBlock),
      borders: measureBorders(node.borders),
      outline: measureOutline(node.outline),
      margins: {
        left: 10,
        right: 10,
        top: 10,
        bottom: 10
      },
      dimensionsConstraints: measureDimensionsConstraints(node.dimensionsConstraints, containingBlock)
    }

      //measure width, height and margins at the same time, as margins can influence or be
      //influenced by the width and height of the HTMLElement
      //measureDimensionsAndMargins(style, containingBlockData);

      //measure the top, left, right and bottom offsets
      //used when the element is 'positioned' (any position style
      //but 'static')
      //if (style.isPositioned == true)
      //{
        //measurePositionOffsets(style, containingBlockData);
      //}

      //At this point, all the dimensions of the HTMLElement are known maybe except the
      //content height if it was set to 'auto' and thus depends on its content's height.
      //Those dimensions are now enough to layout each of the HTMLElement's children.
      //If the parent's height of this HTMLElement is set to 'auto', it will use the
      //computed dimensions of this HTMLElement to compute its own height.
  }

  //private function measureDimensionsAndMargins(style:CoreStyle, containingBlockData:ContainingBlockVO):Void
  //{
    ////compute the margins and the constrained width and height
    //style.usedValues.width = constrainWidth(style, measureWidthAndHorizontalMargins(style, containingBlockData));
    //style.usedValues.height = constrainHeight(style, measureHeightAndVerticalMargins(style, containingBlockData));
  //}


  static function measureWidth(
      width:Dimension,
      maxWidth: Option<Int>,
      minWidth: Option<Int>,
      containingBlock:ContainingBlock):Int {
    return constrainWidth(getComputedWidth(width, containingBlock), maxWidth, minWidth);

    //get the content width (width without margins and paddings)
    //width must be constrained now, so that margin will be computed with the
    //actually used width value
    //var computedWidth = constrainWidth(style, getComputedWidth(style, containingBlock));
    
    //left margin
    //style.usedValues.marginLeft = getComputedMarginLeft(style, computedWidth, containingBlockData);
    //right margin
    //style.usedValues.marginRight = getComputedMarginRight(style, computedWidth, containingBlockData);
    
    //return computedWidth;
  }

  /**
   * Compute the size of the width when 'auto' and return it as pixels. It is equal to
   * the remaining width of the containing HTMLElement once the margins, paddings and borders width have been
   * removed
   */
  static function getComputedAutoWidth(
      paddings:PaddingsUsedValues,
      borders:BordersUsedValues,
      marginLeft:Int,
      marginRight:Int,
      containingBlock:ContainingBlock):Int
    return containingBlock.width - paddings.left - paddings.right - borders.left - borders.right - marginLeft - marginRight;

  static function measureAutoWidth(
      node:StyleNode,
      usedPaddings:PaddingsUsedValues,
      usedBorders:BordersUsedValues,
      containingBlock:ContainingBlock
      ):Int {

    var marginLeft = getComputedMarginLeft(
        node.margins,
        usedPaddings,
        usedBorders,
        0,
        true,
        containingBlock
        );

    var marginRight = getComputedMarginRight(
        node.margins,
        usedPaddings,
        usedBorders,
        0,
        true,
        containingBlock
        );

    //the width is computed now that the sizes of the margins are computed
    return getComputedAutoWidth(usedPaddings, usedBorders, marginLeft, marginRight, containingBlock);
    
    //apply min-width and max-width constrain to the computed width
    //var constrainedWidth:Float = constrainWidth(style, computedWidth);
    
    ////if the width was indeed constrain
    //if (constrainedWidth != computedWidth)
    //{
      ////and if both the left and right margin are auto, then they takes each half of the remaining space in the
      ////containing block so the element will be centered in its containing block
      //if (style.hasAutoMarginLeft && style.hasAutoMarginRight)
      //{
        //var marginWidth:Float = (containingBlockData.width - style.usedValues.paddingLeft - style.usedValues.paddingRight - style.usedValues.borderLeftWidth - style.usedValues.borderRightWidth - constrainedWidth) / 2;
        
        //style.usedValues.marginLeft = marginWidth;
        //style.usedValues.marginRight = marginWidth;
      //}
    //}
    
    //return computedWidth;
  }

  static function measureWidthAndHorizontalMargins(
      node:StyleNode,
      usedPaddings:PaddingsUsedValues,
      usedBorders:BordersUsedValues,
      usedConstraints:DimensionsConstraintsUsedValues, 
      containingBlock:ContainingBlock):Int
    return switch (node.dimensions.width) {
      case Auto: measureAutoWidth(node, usedPaddings, usedBorders, containingBlock);
      case _: measureWidth(node.dimensions.width, usedConstraints.maxWidth, usedConstraints.minWidth, containingBlock);
    }

  @:allow(core.boxmodel.BoxModelTest)
  static function constrainWidth(width:Int, maxWidth:Option<Int>, minWidth:Option<Int>):Int {
    var maxedWidth = switch(maxWidth) {
      case Some(max): if (width > max) max else width;
      case None: width;
    }

    return switch(minWidth) {
      case Some(min): if (width < min) min else maxedWidth;
      case None: maxedWidth;
    }
  }

  static function getComputedWidth(width:Dimension, containingBlock:ContainingBlock):Int {
    return getComputedDimension(width, containingBlock.width);
  }

  static function getComputedDimension(dimension:Dimension, containerDimension:Int):Int {
    return switch (dimension) {
      case AbsoluteLength(value): value;
      case Percent(percent): percent.compute(containerDimension);
      case Auto: 0;
    }
  }

  static function getComputedMarginLeft(
      margins:Margins,
      usedPaddings:PaddingsUsedValues,
      usedBorders:BordersUsedValues,
      width:Int,
      hasAutoWidth:Bool,
      containingBlock:ContainingBlock):Int {
    return getComputedMargin(
        margins.left,
        margins.right,
        containingBlock.width,
        width,
        hasAutoWidth,
        usedPaddings.left + usedPaddings.right + usedBorders.left + usedBorders.right,
        true
        );
  }

  static function getComputedMarginRight(
      margins:Margins,
      usedPaddings:PaddingsUsedValues,
      usedBorders:BordersUsedValues,
      width:Int,
      hasAutoWidth:Bool,
      containingBlock:ContainingBlock):Int {
    return getComputedMargin(
        margins.right,
        margins.left,
        containingBlock.width,
        width,
        hasAutoWidth,
        usedPaddings.left + usedPaddings.right + usedBorders.left + usedBorders.right,
        true
        );
  }

  static function getComputedMargin(
      margin:Margin,
      oppositeMargin:Margin,
      containerDimension:Int,
      dimension:Int,
      dimensionIsAuto:Bool,
      paddingsAndBordersDimension:Int,
      isHorizontalMargin:Bool):Int {
    return switch (margin) {

      case AbsoluteLength(value): value;

      case Percent(percent):
        if (dimensionIsAuto) 0;
        else percent.compute(containerDimension);

      case Auto:
        getComputedAutoMargin(
            margin,
            oppositeMargin,
            containerDimension,
            dimension,
            dimensionIsAuto,
            paddingsAndBordersDimension,
            isHorizontalMargin
            );
    }
  }

  static function getComputedAutoMargin(
      margin:Margin,
      oppositeMargin:Margin,
      containerDimension:Int,
      computedDimension:Int,
      dimensionIsAuto:Bool,
      paddingsAndBordersDimension:Int,
      marginIsHorizontal:Bool):Int {
    return
      if (!marginIsHorizontal || dimensionIsAuto) 0;
      else return switch (oppositeMargin) {
        case Auto:
          Math.round((containerDimension - computedDimension - paddingsAndBordersDimension) / 2);

        case _:
          var oppositeMarginDimension = getComputedMargin(
              oppositeMargin,
              margin,
              containerDimension,
              computedDimension,
              dimensionIsAuto,
              paddingsAndBordersDimension,
              marginIsHorizontal);
          containerDimension - computedDimension - paddingsAndBordersDimension - oppositeMarginDimension; 
      }
  }

  /**
   * Constrain computed width if it is above/below max/min width
   */
  //private function constrainWidth(style:CoreStyle, usedWidth:Float):Float
  //{
    //var usedValues:UsedValuesVO = style.usedValues;

    ////check that the computedWidth is not 
    ////superior to max width. The max width
    ////can be defined as "none" if there are 
    ////no width limit on this HTMLElement
    //if (style.hasMaxWidth == true)
    //{
      //if (usedWidth > usedValues.maxWidth)
      //{
        //usedWidth = usedValues.maxWidth;
      //}
    //}
    
    ////check that width is superior to min width
    //if (usedWidth < usedValues.minWidth)
    //{
      //usedWidth = usedValues.minWidth;
    //}
    
    //return usedWidth;
  //}
  
  /**
   * Constrain computed height if it is above/below max/min height
   */
  //private function constrainHeight(style:CoreStyle, usedHeight:Float):Float
  //{
    //var usedValues:UsedValuesVO = style.usedValues;
  
    ////check that height is within authorised range
    //if (style.hasMaxHeight == true)
    //{
      //if (usedHeight > usedValues.maxHeight)
      //{
        //usedHeight = usedValues.maxHeight;
      //}
    //}
    
    ////check that height is superior to min height
    //if (usedHeight < usedValues.minHeight)
    //{
      //usedHeight = usedValues.minHeight;
    //}
    
    //return usedHeight;
  //}

  static function measureOutline(outline:Outline):Int {
    return switch(outline) {
      case AbsoluteLength(value): value;
    }
  }

  static function measureBorders(borders:Borders):BordersUsedValues {
    return {
      left : getComputedBorderWidth(borders.left),
      right: getComputedBorderWidth(borders.right),
      top: getComputedBorderWidth(borders.top),
      bottom: getComputedBorderWidth(borders.bottom)
    }
  }

  static function getComputedBorderWidth(border:Border):Int {
    return switch (border) {
      case AbsoluteLength(value): value;
    }
  }

  static function measurePaddings(paddings:Paddings, containingBlock:ContainingBlock):PaddingsUsedValues {
    return {
      left: getComputedPadding(paddings.left, containingBlock.width),
      right: getComputedPadding(paddings.right, containingBlock.width),
      top: getComputedPadding(paddings.top, containingBlock.width),
      bottom: getComputedPadding(paddings.bottom, containingBlock.width),
    }
  }

  @:allow(core.boxmodel.BoxModelTest)
  static function getComputedPadding(padding:Padding, containerWidth:Int):Int {
    return switch (padding) {
      case AbsoluteLength(value): value;
      case Percent(percent): percent.compute(containerWidth);
    }
  }

  static function measureDimensionsConstraints(constraints:DimensionsConstraints, containingBlock:ContainingBlock):DimensionsConstraintsUsedValues {
    return {
      maxHeight: getComputedConstrainedDimension(constraints.maxHeight, containingBlock.height, containingBlock.isHeightAuto),
      minHeight: getComputedConstrainedDimension(constraints.minHeight, containingBlock.height, containingBlock.isHeightAuto),
      maxWidth: getComputedConstrainedDimension(constraints.maxWidth, containingBlock.width, containingBlock.isWidthAuto),
      minWidth: getComputedConstrainedDimension(constraints.minWidth, containingBlock.width, containingBlock.isWidthAuto)
    }
  }

  @:allow(core.boxmodel.BoxModelTest)
  static function getComputedConstrainedDimension(constraint:DimensionConstraint, containerDimension:Int, containingDimensionIsAuto:Bool):Option<Int> {
    return switch (constraint) {
      case AbsoluteLength(value): Some(value);

      case Percent(percent):
        if (containingDimensionIsAuto) None;
        else Some(percent.compute(containerDimension));

      case Unconstrained: None;
    }
  }
}

abstract Percentage(Int) from Int {

  inline function new (i) this = i;

  public inline function compute(reference:Int)
    return Math.round(reference * (this * 0.01));

}

typedef StyleNode = {
  var paddings:Paddings;
  var borders:Borders;
  var margins:Margins;
  var dimensions:Dimensions;
  var outline:Outline;
  var dimensionsConstraints:DimensionsConstraints;
}

typedef UsedStyleNode = {
  var paddings:PaddingsUsedValues;
  var borders:BordersUsedValues;
  var margins:MarginsUsedValues;
  var outline:Int;
  var dimensionsConstraints:DimensionsConstraintsUsedValues;
}

typedef DimensionsConstraints = {
  var minHeight:DimensionConstraint;
  var maxHeight:DimensionConstraint;
  var minWidth:DimensionConstraint;
  var maxWidth:DimensionConstraint;
}

typedef DimensionsConstraintsUsedValues = {
  var minHeight:Option<Int>;
  var maxHeight:Option<Int>;
  var minWidth:Option<Int>;
  var maxWidth:Option<Int>;
}

enum DimensionConstraint {
  AbsoluteLength(value:Int);
  Percent(value:Percentage);
  Unconstrained;
}

enum Border {
  AbsoluteLength(value:Int);
}

enum Outline {
  AbsoluteLength(value:Int);
}

enum Dimension {
  AbsoluteLength(value:Int);
  Percent(value:Percentage);
  Auto;
}

typedef Dimensions = {
  var width:Dimension;
  var height:Dimension;
}

enum Margin {
  AbsoluteLength(value:Int);
  Percent(value:Percentage);
  Auto;
}

typedef Margins = {
  var left:Margin;
  var right:Margin;
  var top:Margin;
  var bottom:Margin;
}

typedef Borders = {
  var left:Border;
  var right:Border;
  var top:Border;
  var bottom:Border;
}

typedef MarginsUsedValues = {
  var left:Int;
  var right:Int;
  var top:Int;
  var bottom:Int;
}

typedef BordersUsedValues = {
  var left:Int;
  var right:Int;
  var top:Int;
  var bottom:Int;
}

enum Padding {
  AbsoluteLength(value:Int);
  Percent(value:Percentage);
}

typedef Paddings = {
  var left:Padding;
  var right:Padding;
  var top:Padding;
  var bottom:Padding;
}

typedef PaddingsUsedValues = {
  var left:Int;
  var right:Int;
  var top:Int;
  var bottom:Int;
}

typedef ContainingBlock = {
  var width:Int;
  var height:Int;
  var isHeightAuto:Bool;
  var isWidthAuto:Bool;
}

