package hxtml;

#if macro
import haxe.macro.Context;
import haxe.macro.Expr;
#end

class Macros  {

	@:macro public static function copyVars( to : Expr, from : Expr ) {
		var t = Context.typeof(from);
		var sets = [];
		var p = Context.currentPos();
		var enull = { expr : EConst(CIdent("null")), pos : p };
		switch( t ) {
		case TInst(c, _):
			for( f in c.get().fields.get() )
				switch( f.kind ) {
				case FVar(_):
					var val = { expr : EField(from, f.name), pos : p };
					var cond = { expr : EBinop(OpNotEq, val, enull), pos : p };
					var assign = { expr : EBinop(OpAssign, { expr : EField(to, f.name), pos : p }, val), pos : p };
					sets.push( { expr : EIf(cond, assign, null), pos : p } );
				default:
				}
		default:
			Context.error("Unsupported type", p);
		};
		return { expr : EBlock(sets), pos : p };
	}
}