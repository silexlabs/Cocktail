haxe build_cheers.hxml -D build_for_flash
openfl build html5 -debug
cp -r ./bin/html5/bin/res ./bin
cp ./bin/html5/bin/CocktailDemo.js ./bin
cp ./bin/html5/bin/CocktailDemo.js.map ./bin
openfl build flash -debug
