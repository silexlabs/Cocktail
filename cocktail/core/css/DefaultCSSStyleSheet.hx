/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.css;

import cocktail.core.css.CSSData;

/**
 * A default CSS stylesheet corresponding to the user agent (cocktail)
 * stylsheet. It is taken from the w3c default style sheet recommandation :
	 * http://www.w3.org/TR/CSS21/sample.html
 * 
 * @author Yannick DOMINGUEZ
 */
class DefaultCSSStyleSheet extends CSSStyleSheet
{
	/**
	 * class onstructor
	 */
	public function new() 
	{
		super(getDefaultStyleSheet(), PropertyOriginValue.USER_AGENT);
	}
	
	/**
	 * Return Cocktail's default style sheet
	 */
	private function getDefaultStyleSheet():String
	{

		//TODO 3 : li for now is defined as "block" instead of "list-item"
		return "
				html, address,
				blockquote,
				body, dd, div,
				dl, dt, fieldset, form,
				frame, frameset,
				h1, h2, h3, h4,
				h5, h6, noframes,
				ol, p, ul, center,
				dir, hr, menu, pre, nav   { display: block; unicode-bidi: embed }
				li              { display: block }
				head            { display: none }
				table           { display: table }
				tr              { display: table-row }
				thead           { display: table-header-group }
				tbody           { display: table-row-group }
				tfoot           { display: table-footer-group }
				col             { display: table-column }
				colgroup        { display: table-column-group }
				td, th          { display: table-cell }
				caption         { display: table-caption }
				th              { font-weight: bolder; text-align: center }
				caption         { text-align: center }
				body            { margin: 8px }
				h1              { font-size: 2em; margin: .67em 0 }
				h2              { font-size: 1.5em; margin: .75em 0 }
				h3              { font-size: 1.17em; margin: .83em 0 }
				h4, p,
				blockquote, ul,
				fieldset, form,
				ol, dl, dir,
				menu            { margin: 1em 0 }
				h5              { font-size: .83em; margin: 1.5em 0 }
				h6              { font-size: .75em; margin: 1.67em 0 }
				h1, h2, h3, h4,
				h5, h6, b,
				strong          { font-weight: bolder }
				blockquote      { margin-left: 40px; margin-right: 40px }
				i, cite, em,
				var, address    { font-style: italic }
				pre, tt, code,
				kbd, samp       { font-family: monospace }
				pre             { white-space: pre }
				button, textarea,
				input, select   { display: inline-block }
				big             { font-size: 1.17em }
				small, sub, sup { font-size: .83em }
				sub             { vertical-align: sub }
				sup             { vertical-align: super }
				table           { border-spacing: 2px; }
				thead, tbody,
				tfoot           { vertical-align: middle }
				td, th, tr      { vertical-align: inherit }
				s, strike, del  { text-decoration: line-through }
				hr              { border: 1px inset }
				ol, ul, dir,
				menu, dd        { margin-left: 40px }
				ol              { list-style-type: decimal }
				ol ul, ul ol,
				ul ul, ol ol    { margin-top: 0; margin-bottom: 0 }
				u, ins          { text-decoration: underline }
				
				center          { text-align: center }
				:link, :visited { text-decoration: underline; cursor:pointer; }
				:focus          { outline: thin dotted invert }
				
				a:link          { color: rgb(0, 0, 238) }
				a:active        { color: red }
				
				input[type=button] {
					background-image:url('button.png');
					font:13px sans-serif;
					text-align:center;
					color:#505050;
					width:74px;
					height:18px;
					padding-top:6px;
				}
				
				input[type=button]:hover {
					background-position:-74px 0;
					color:#734b1f;
				}
				
				input[type=button]:active {
					background-position:-148px 0;
					color:#854500;
				}
				
				input[type=checkbox] {
					background-image:url('checkbox.png');
				}
				
				input[type=radio] {
					background-image:url('radio.png');
				}
				
				input[type=checkbox], input[type=radio] {
					height:16px;
					width:16px;
					background-position:-64px 0;
				}
				
				input[type=checkbox]:hover, input[type=radio]:hover {
					background-position:-80px 0;
				}
				
				input[type=checkbox]:active, input[type=radio]:active {
					background-position:-96px 0;
				}
				
				input[type=checkbox]:checked, input[type=radio]:checked {
					background-position:0;
				}
				
				input[type=checkbox]:checked:hover, input[type=radio]:checked:hover {
					background-position:-16px;
				}
				
				input[type=checkbox]:checked:active, input[type=radio]:checked:active {
					background-position:-32px;
				}
				
				input[type=checkbox]:disabled, input[type=radio]:disabled {
					background-position:-48px;
				}
				
				input[type=checkbox]:checked:disabled, input[type=radio]:checked:disabled {
					background-position:-112px;
				}
		";
	}
	
}