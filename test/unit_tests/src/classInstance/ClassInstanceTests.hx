/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package classInstance;


import cocktail.core.nativeInstance.NativeInstanceManager;
import cocktail.core.ClassInstance;
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