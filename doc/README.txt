GENERATING THE DOC
-----------------------

The doc is generated using the Haxe lib chxdoc.
It is use instead of haxedoc for the following feature :
- support of JavaDoc tag (like @param)
- easier styling with external style sheet
- styled generated doc out-of-the-box

To compile the doc, you must install chxdoc with the following command lines : 

haxelib install chxdoc
haxelib run chxdoc install [optional path]

The first line install the chxdoc library in your haxe install folder,
the second one compile chxdoc into an executable in the "optionnal path" directory.
It is recommended that the "optionnal path" points to the same directory as this
README because the .hxml generating the doc assumes that the executable is here.