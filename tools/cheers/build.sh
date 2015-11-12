haxe build_cheers.hxml
openfl build html5 -debug
cp -r ./bin/html5/bin/res ./bin
cp ./bin/html5/bin/CocktailDemo.js ./bin
cp ./bin/html5/bin/CocktailDemo.js.map ./bin
haxe build_cocktail_browser.hxml
