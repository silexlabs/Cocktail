/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package classInstance;


import haxe.Log;
import cocktail.nativeInstance.NativeInstanceManager;
import cocktail.classInstance.ClassInstance;
import utest.Assert;
import utest.Runner;
import utest.ui.Report;


/**
 * Test the cross-platform native class instance proxy 
 *@author Yannick DOMINGUEZ
 */
class ClassInstanceTests 
{
	public static function main()
	{
		var runner = new Runner();
		runner.addCase(new ClassInstanceTests());
		Report.create(runner);
		runner.run();
	}
	
	public function new() 
	{
		
	}
	
	public function testNativeClassInstance()
	{
		var classInstance:ClassInstance = NativeInstanceManager.getClassInstanceByClassName("classInstance.TestClass");
		
		//test native instance methods
		Assert.isNull(classInstance.getField("testAttribute"));
		
		Assert.equals(classInstance.callMethod("testMethod", []), "test OK");
		
		classInstance.setField("_testAttribute", "new value");
		Assert.equals(classInstance.getField("_testAttribute"), "new value");
		
		classInstance.setField("testAttribute", "new setter value");
		Assert.equals(classInstance.getField("testAttribute"), "new setter value");
		
		
	}
	
}

/**
 * This is a test class, used as a native class
 * wrapped in a ClassInstance
 */
class TestClass
{
	public var testAttribute(getTestAttribute, setTestAttribute):String;
	
	private var _testAttribute:String;
	
	public function new()
	{
	
	}
	
	public function testMethod():String
	{
		return "test OK";
	}
	
	private function setTestAttribute(value:String):String
	{
		_testAttribute = value;
		return _testAttribute;
	}
	
	private function getTestAttribute():String
	{
		return _testAttribute;
	}
}