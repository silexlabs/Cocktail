import js.Lib;

/**
 * Basic DOM manipulation
 */
class Sample
{
	public function new()
	{
		var title = Lib.document.createElement("h1");
		title.appendChild(Lib.document.createTextNode("Hello World ! "));
		
		var text = Lib.document.createTextNode("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Cras dignissim lorem a purus semper scelerisque. Mauris eu quam lacus, a pellentesque neque. Suspendisse nec tristique turpis. Mauris et eros non nisi congue condimentum. Aliquam erat volutpat. Integer eget dignissim libero. Aliquam tellus odio, mollis vel pellentesque at, dapibus pulvinar mi. Ut convallis, quam nec tincidunt porttitor, velit odio pharetra lectus, sit amet sodales lacus risus in urna. Aliquam imperdiet, massa ut placerat viverra, justo odio tempor purus, a ultricies neque lectus vel ipsum.");
		
		Lib.document.body.appendChild(title);
		Lib.document.body.appendChild(text);
	}

	public static function main()
	{
		#if nme
			nme.Lib.create(function() { new Sample(); }, 1024, 768, 60, 0xffffff, (1 * nme.Lib.HARDWARE) | nme.Lib.RESIZABLE);
		#else
		     new Sample();
		#end
	}

}
