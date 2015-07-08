package cocktail.core.boxmodel2;


class BoxModel {

  public static function measure(node:StyleNode, containingBlock:ContainingBlock):UsedStyleNode {
    return {
      paddings: measurePaddings(node.paddings, containingBlock),
      borders: measureBorders(node.borders),
      outline: measureOutline(node.outline),
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

  private static function measureOutline(outline:Outline):Int {
    return switch(outline) {
      case AbsoluteLength(value): value;
    }
  }

  private static function measureBorders(borders:Borders):BordersUsedValues {
    return {
      left : getComputedBorderWidth(borders.left),
      right: getComputedBorderWidth(borders.right),
      top: getComputedBorderWidth(borders.top),
      bottom: getComputedBorderWidth(borders.bottom)
    }
  }

  private static function getComputedBorderWidth(border:Border):Int {
    return switch (border) {
      case AbsoluteLength(value): value;
    }
  }

  private static function measurePaddings(paddings:Paddings, containingBlock:ContainingBlock):PaddingsUsedValues {
    return {
      left: getComputedPadding(paddings.left, containingBlock.width),
      right: getComputedPadding(paddings.right, containingBlock.width),
      top: getComputedPadding(paddings.top, containingBlock.width),
      bottom: getComputedPadding(paddings.bottom, containingBlock.width),
    }
  }

  @:allow(core.boxmodel.BoxModelTest)
  private static function getComputedPadding(padding:Padding, containerWidth:Int):Int {
    return switch (padding) {
      case AbsoluteLength(value): value;
      case Percent(value): Math.round(containerWidth * (value * 0.01));
    }
  }

  private static function measureDimensionsConstraints(constraints:DimensionsConstraints, containingBlock:ContainingBlock):DimensionsConstraintsUsedValues {
    return {
      maxHeight: getComputedConstrainedDimension(constraints.maxHeight, containingBlock.height, containingBlock.isHeightAuto, false),
      minHeight: getComputedConstrainedDimension(constraints.minHeight, containingBlock.height, containingBlock.isHeightAuto, true),
      maxWidth: getComputedConstrainedDimension(constraints.maxWidth, containingBlock.width, containingBlock.isWidthAuto, false),
      minWidth: getComputedConstrainedDimension(constraints.minWidth, containingBlock.width, containingBlock.isWidthAuto, true)
    }
  }

  private static function getComputedConstrainedDimension(constraint:DimensionConstraint, containerDimension:Int, isContainingDimensionAuto:Bool, isMinConstraint:Bool):Int {
    return switch (constraint) {
      case AbsoluteLength(value): value;

      case Percent(value):
        //if the containing HTMLElement dimension is not defined,
        //min value default to 0, for max value,
        //default to an "infinite" value (no constraints)
        if (isContainingDimensionAuto == true) {
          if (isMinConstraint == true) {
            0;
          }
          else {
            1000000;
          }
        }
        else {
          Math.round(containerDimension * (value * 0.01));
        }

      case None:
        if (isMinConstraint == true) {
          0;
        }
        else {
          1000000;
        }
    }
  }
}

typedef StyleNode = {
  var paddings:Paddings;
  var borders:Borders;
  var outline:Outline;
  var dimensionsConstraints:DimensionsConstraints;
}

typedef UsedStyleNode = {
  var paddings:PaddingsUsedValues;
  var borders:BordersUsedValues;
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
  var minHeight:Int;
  var maxHeight:Int;
  var minWidth:Int;
  var maxWidth:Int;
}

enum DimensionConstraint {
  AbsoluteLength(value:Int);
  Percent(value:Int);
  None;
}

enum Border {
  AbsoluteLength(value:Int);
}

enum Outline {
  AbsoluteLength(value:Int);
}

typedef Borders = {
  var left:Border;
  var right:Border;
  var top:Border;
  var bottom:Border;
}

typedef BordersUsedValues = {
  var left:Int;
  var right:Int;
  var top:Int;
  var bottom:Int;
}

enum Padding {
  AbsoluteLength(value:Int);
  Percent(value:Int);
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

