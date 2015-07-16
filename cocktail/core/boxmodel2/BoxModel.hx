package cocktail.core.boxmodel2;

import haxe.ds.Option;

class BoxModel {

  public static function measure(styles:Styles, containingBlock:ContainingBlock):UsedStyles {

    var paddings = getPaddings(styles.paddings, containingBlock);
    var borders = getBorders(styles.borders);
    var constraints = getConstraints(styles.constraints, containingBlock);

    var autoMargins = getMargins(
        styles.display,
        styles.margins,
        paddings,
        borders,
        {width: 0, height: 0},
        true,
        true,
        containingBlock
        );

    var isFloated = switch(styles.float) {
      case Left, Right: true;
      case Unfloated: false;
    }

    var isInline = switch(styles.display) {
      case Inline, InlineBlock: !isFloated;
      case Block: false;
    }

    var width = getWidth(
        styles.dimensions.width,
        autoMargins,
        paddings,
        borders,
        constraints,
        containingBlock,
        isFloated,
        isInline);

    var positions = getPositions(styles.positions, containingBlock);

    var height = getHeight(styles.dimensions.height, constraints, containingBlock, isInline);

    var dimensions = {
      width: width,
      height: height
    }

    var margins = getMargins(
        styles.display,
        styles.margins,
        paddings,
        borders,
        dimensions,
        styles.dimensions.width == Auto,
        styles.dimensions.height == Auto,
        containingBlock
        );

    return {
      paddings: paddings,
      borders: borders,
      outline: getOutline(styles.outline),
      dimensions: dimensions,
      margins: margins,
      constraints: constraints,
      positions: positions
    }
  }

  static function getPositions(positions:Positions, containingBlock:ContainingBlock):UsedPositions {
    return {
      left: getPosition(positions.left, containingBlock.width),
      right: getPosition(positions.right, containingBlock.width),
      top: getPosition(positions.top, containingBlock.height),
      bottom: getPosition(positions.bottom, containingBlock.height)
    }
  }

  static function getPosition(position:Position, containingDimension:Int) {
    return switch(position) {
      case AbsoluteLength(value): value;
      case Percent(percent): percent.compute(containingDimension);
    }
  }

  @:allow(core.boxmodel.BoxModelTest)
  static function getHeight(
      height:Dimension,
      constraints:UsedConstraints,
      containingBlock:ContainingBlock,
      isInline:Bool
      ):Int {
    return
      if (isInline) 0;
      else constrainDimension(
        getDimension(height, containingBlock.height),
        constraints.maxHeight, constraints.minHeight
        );
  }

  @:allow(core.boxmodel.BoxModelTest)
  static function getAutoWidth(
      paddings:UsedPaddings,
      borders:UsedBorders,
      marginLeft:Int,
      marginRight:Int,
      containingBlock:ContainingBlock):Int
    return containingBlock.width - paddings.left - paddings.right - borders.left - borders.right - marginLeft - marginRight;

  @:allow(core.boxmodel.BoxModelTest)
  static function getWidth(
      width:Dimension,
      margins:UsedMargins,
      paddings:UsedPaddings,
      borders:UsedBorders,
      constraints:UsedConstraints,
      containingBlock:ContainingBlock,
      isFloated:Bool,
      isInline:Bool):Int
    return switch (width) {
      case Auto:
        if (isFloated || isInline) 0;
        else getAutoWidth(paddings, borders, margins.left, margins.right, containingBlock);
      case _: constrainDimension(getDimension(width, containingBlock.width), constraints.maxWidth, constraints.minWidth);
    }

  @:allow(core.boxmodel.BoxModelTest)
  static function constrainDimension(dimension:Int, max:Option<Int>, min:Int):Int {
    var maxedDimension = switch(max) {
      case Some(max): if (dimension > max) max else dimension;
      case None: dimension;
    }

    return if (maxedDimension > min) maxedDimension
           else min;
  }

  static function getDimension(dimension:Dimension, containerDimension:Int):Int {
    return switch (dimension) {
      case AbsoluteLength(value): value;
      case Percent(percent): percent.compute(containerDimension);
      case Auto: 0;
    }
  }

  static function getMargins(
      display:Display,
      margins:Margins,
      paddings:UsedPaddings,
      borders:UsedBorders,
      dimensions:UsedDimensions,
      widthIsAuto:Bool,
      heightIsAuto:Bool,
      containingBlock:ContainingBlock
      ):UsedMargins {
    return switch (display) {
      case Block: getBlockMargins(
                      margins,
                      paddings,
                      borders,
                      dimensions,
                      widthIsAuto,
                      heightIsAuto,
                      containingBlock
                      );

      case Inline, InlineBlock: getInlineMargins(
                             margins,
                             widthIsAuto,
                             heightIsAuto,
                             containingBlock
                            );
    }
  }

  static function getInlineMargins(
      margins:Margins,
      widthIsAuto:Bool,
      heightIsAuto:Bool,
      containingBlock:ContainingBlock):UsedMargins {
    return {
      left: getInlineMargin(
          margins.left,
          containingBlock.width,
          widthIsAuto
          ),

      right: getInlineMargin(
          margins.right,
          containingBlock.width,
          widthIsAuto
          ),

      top: getInlineMargin(
          margins.top,
          containingBlock.height,
          heightIsAuto
          ),
      
      bottom: getInlineMargin(
          margins.top,
          containingBlock.height,
          heightIsAuto
          ),
    }
  }

  @:allow(core.boxmodel.BoxModelTest)
  static function getInlineMargin(
      margin:Margin,
      containerDimension:Int,
      dimensionIsAuto:Bool) {
    return switch (margin) {

      case AbsoluteLength(value): value;

      case Percent(percent):
        if (dimensionIsAuto) 0;
        else percent.compute(containerDimension);

      case Auto: 0;
    }
  }

  static function getBlockMargins(
      margins:Margins,
      paddings:UsedPaddings,
      borders:UsedBorders,
      dimensions:UsedDimensions,
      widthIsAuto:Bool,
      heightIsAuto:Bool,
      containingBlock:ContainingBlock
      ):UsedMargins {

    var usedWidth = paddings.left + paddings.right + borders.left + borders.right;
    return {
      left: getBlockMargin(
          margins.left,
          margins.right,
          containingBlock.width,
          dimensions.width,
          widthIsAuto,
          usedWidth,
          true
          ),

      right: getBlockMargin(
          margins.right,
          margins.left,
          containingBlock.width,
          dimensions.width,
          widthIsAuto,
          usedWidth,
          true
          ),

      top: getBlockMargin(
          margins.top,
          margins.bottom,
          containingBlock.height,
          dimensions.height,
          heightIsAuto,
          usedWidth,
          false
          ),

      bottom: getBlockMargin(
          margins.bottom,
          margins.top,
          containingBlock.height,
          dimensions.height,
          heightIsAuto,
          usedWidth,
          false
          )
    }
  }

  @:allow(core.boxmodel.BoxModelTest)
  static function getBlockMargin(
      margin:Margin,
      oppositeMargin:Margin,
      containerDimension:Int,
      dimension:Int,
      dimensionIsAuto:Bool,
      paddingsAndBordersDimension:Int,
      marginIsHorizontal:Bool):Int {
    return switch (margin) {

      case AbsoluteLength(value): value;

      case Percent(percent):
        if (dimensionIsAuto) 0;
        else percent.compute(containerDimension);

      case Auto:
        if(!marginIsHorizontal || dimensionIsAuto) 0;
        else getAutoHorizontalMargin(
              oppositeMargin,
              containerDimension,
              dimension,
              paddingsAndBordersDimension
              );
    }
  }

  @:allow(core.boxmodel.BoxModelTest)
  static function getAutoHorizontalMargin(
      oppositeMargin:Margin,
      containerDimension:Int,
      dimension:Int,
      paddingsAndBordersDimension:Int
      ):Int
    return switch (oppositeMargin) {
      case Auto:
        Math.round((containerDimension - dimension - paddingsAndBordersDimension) / 2);

      case _:
        var oppositeMarginDimension = getBlockMargin(
            oppositeMargin,
            Auto,
            containerDimension,
            dimension,
            false,
            paddingsAndBordersDimension,
            false
            );
        containerDimension - dimension - paddingsAndBordersDimension - oppositeMarginDimension;
    }

  static function getOutline(outline:Outline):Int {
    return switch(outline) {
      case AbsoluteLength(value): value;
    }
  }

  static function getBorders(borders:Borders):UsedBorders {
    return {
      left : getBorder(borders.left),
      right: getBorder(borders.right),
      top: getBorder(borders.top),
      bottom: getBorder(borders.bottom)
    }
  }

  static function getBorder(border:Border):Int {
    return switch (border) {
      case AbsoluteLength(value): value;
    }
  }

  static function getPaddings(paddings:Paddings, containingBlock:ContainingBlock):UsedPaddings {
    return {
      left: getPadding(paddings.left, containingBlock.width),
      right: getPadding(paddings.right, containingBlock.width),
      top: getPadding(paddings.top, containingBlock.width),
      bottom: getPadding(paddings.bottom, containingBlock.width),
    }
  }

  @:allow(core.boxmodel.BoxModelTest)
  static function getPadding(padding:Padding, containerWidth:Int):Int {
    return switch (padding) {
      case AbsoluteLength(value): value;
      case Percent(percent): percent.compute(containerWidth);
    }
  }

  static function getConstraints(constraints:Constraints, containingBlock:ContainingBlock):UsedConstraints {
    return {
      maxHeight: getMaxConstraint(constraints.maxHeight, containingBlock.height, containingBlock.isHeightAuto),
      minHeight: getMinConstraint(constraints.minHeight, containingBlock.height, containingBlock.isHeightAuto),
      maxWidth: getMaxConstraint(constraints.maxWidth, containingBlock.width, containingBlock.isWidthAuto),
      minWidth: getMinConstraint(constraints.minWidth, containingBlock.width, containingBlock.isWidthAuto)
    }
  }

  @:allow(core.boxmodel.BoxModelTest)
  static function getMaxConstraint(constraint:MaxConstraint, containerDimension:Int, containingDimensionIsAuto:Bool):Option<Int> {
    return switch (constraint) {
      case AbsoluteLength(value): Some(value);

      case Percent(percent):
        if (containingDimensionIsAuto) None;
        else Some(percent.compute(containerDimension));

      case Unconstrained: None;
    }
  }

  static function getMinConstraint(constraint:MinConstraint, containerDimension:Int, containingDimensionIsAuto:Bool):Int {
    return switch (constraint) {
      case AbsoluteLength(value): value;

      case Percent(percent):
        if (containingDimensionIsAuto) 0;
        else percent.compute(containerDimension);
    }
  }

  @:allow(core.boxmodel.BoxModelTest)
  static function fixConstraintViolation(
      width:Int,
      height:Int,
      constraints:UsedConstraints
      ):UsedDimensions {

    return switch [
      constraints.maxWidth,
      constraints.minWidth,
      constraints.maxHeight,
      constraints.minHeight
    ] {
      case [Some(maxWidth), _, Some(maxHeight), minHeight] if (maxWidth / width <= maxHeight / height): {
        width: maxWidth,
        height: Math.round(Math.max(minHeight, maxWidth * (height / width)))
      }
      case [Some(maxWidth), minWidth, Some(maxHeight), _] if (maxWidth / width > maxHeight / height): {
        width: Math.round(Math.max(minWidth, maxHeight * (width / height))),
        height: maxHeight,
      }
      case [Some(maxWidth), _, _, minHeight] if (height < minHeight): {
        width: Math.round(Math.min(minHeight * (width / height), maxWidth)),
        height: minHeight
      }
      case [None, _, _, minHeight] if (height < minHeight): {
        width: Math.round(minHeight * (width / height)),
        height: minHeight
      }
      case [_, minWidth, Some(maxHeight), _] if (height > maxHeight): {
        width: Math.round(Math.max(maxHeight * (width / height), minWidth)),
        height: maxHeight
      }
      case [Some(maxWidth), _, _, minHeight] if (width > maxWidth): {
        width: maxWidth,
        height: Math.round(Math.max(maxWidth * (height / width), minHeight))
      }
      case [_, minWidth, Some(maxHeight), _] if (width < minWidth): {
        width: minWidth,
        height: Math.round(Math.min(minWidth * (height / width), maxHeight))
      }
      case [_, minWidth, None, _] if (width < minWidth): {
        width: minWidth,
        height: Math.round(minWidth * (height / width))
      }
      case _: {
        width: width,
        height: height
      };
    }
  }
}

abstract Percentage(Int) from Int {

  inline function new (i) this = i;

  public inline function compute(reference:Int)
    return Math.round(reference * (this * 0.01));

}

typedef Styles = {
  var display:Display;
  var float:CSSFloat;
  var paddings:Paddings;
  var borders:Borders;
  var margins:Margins;
  var dimensions:Dimensions;
  var outline:Outline;
  var constraints:Constraints;
  var positions:Positions;
}

enum Display {
   Block;
   InlineBlock;
   Inline;
}

enum CSSFloat {
  Left;
  Right;
  Unfloated;
}

typedef UsedStyles = {
  var paddings:UsedPaddings;
  var borders:UsedBorders;
  var margins:UsedMargins;
  var dimensions:UsedDimensions;
  var outline:Int;
  var constraints:UsedConstraints;
  var positions:UsedPositions;
}

typedef Constraints = {
  var minHeight:MinConstraint;
  var maxHeight:MaxConstraint;
  var minWidth:MinConstraint;
  var maxWidth:MaxConstraint;
}

typedef UsedConstraints = {
  var minHeight:Int;
  var maxHeight:Option<Int>;
  var minWidth:Int;
  var maxWidth:Option<Int>;
}

enum MaxConstraint {
  AbsoluteLength(value:Int);
  Percent(value:Percentage);
  Unconstrained;
}

enum MinConstraint {
  AbsoluteLength(value:Int);
  Percent(value:Percentage);
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

typedef UsedDimensions = {
   var width:Int;
   var height:Int;
}

enum Margin {
  AbsoluteLength(value:Int);
  Percent(value:Percentage);
  Auto;
}

typedef Positions = {
  var left:Position;
  var right:Position;
  var top:Position;
  var bottom:Position;
}

enum Position {
  AbsoluteLength(value:Int);
  Percent(value:Percentage);
}

typedef UsedPositions = {
  var left:Int;
  var right:Int;
  var top:Int;
  var bottom:Int;
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

typedef UsedMargins = {
  var left:Int;
  var right:Int;
  var top:Int;
  var bottom:Int;
}

typedef UsedBorders = {
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

typedef UsedPaddings = {
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

