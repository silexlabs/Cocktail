# use:
# ./create-embed-font.sh source className fontName fontWeight fontStyle mimeType unicodeRange
# source
# className
# fontName
# fontWeight = normal,bold,heavy
# fontStyle = normal,italic,oblique
# mimeType = application/x-font,application/x-font-truetype
# unicodeRange
# see http://inspiritgames.com/blog/2010/09/embed-fonts-into-pure-as3-project/

echo $3
# replace the values in the template by params
cp FontClassTemplate.as FontClassTemplate.tmp.as
sed "s/%source/$1/g" FontClassTemplate.tmp.as > FontClassTemplate.tmp2.as
cp FontClassTemplate.tmp2.as FontClassTemplate.tmp.as
sed "s/%className/$2/g" FontClassTemplate.tmp.as > FontClassTemplate.tmp2.as
cp FontClassTemplate.tmp2.as FontClassTemplate.tmp.as
sed "s/%fontName/$3/g" FontClassTemplate.tmp.as > FontClassTemplate.tmp2.as
cp FontClassTemplate.tmp2.as FontClassTemplate.tmp.as
sed "s/%fontWeight/$4/g" FontClassTemplate.tmp.as > FontClassTemplate.tmp2.as
cp FontClassTemplate.tmp2.as FontClassTemplate.tmp.as
sed "s/%fontStyle/$5/g" FontClassTemplate.tmp.as > FontClassTemplate.tmp2.as
cp FontClassTemplate.tmp2.as FontClassTemplate.tmp.as
sed "s/%mimeType/$6/g" FontClassTemplate.tmp.as > FontClassTemplate.tmp2.as
cp FontClassTemplate.tmp2.as FontClassTemplate.tmp.as
sed "s/%unicodeRange/$7/g" FontClassTemplate.tmp.as > FontClassTemplate.tmp2.as
cp FontClassTemplate.tmp2.as FontClassTemplate.tmp.as

# remove empty params
sed 's/\,\ [A-z]*=\"\"//g' FontClassTemplate.tmp.as > FontClassTemplate.tmp2.as
cp FontClassTemplate.tmp2.as FontClassTemplate.tmp.as

cp FontClassTemplate.tmp.as $2.as

mxmlc $2.as -static-link-runtime-shared-libraries=true
rm FontClassTemplate.tmp.as FontClassTemplate.tmp2.as $2.as