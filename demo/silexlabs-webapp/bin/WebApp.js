
$estr=function(){return js.Boot.__string_rec(this,'');}
WebAppStyle=function(){}
WebAppStyle.__name__=["WebAppStyle"];WebAppStyle.getDefaultStyle=function(domElement){domElement.style.minHeight="130%";}
WebAppStyle.getBodyStyle=function(domElement){WebAppStyle.getDefaultStyle(domElement);domElement.style.position="static";domElement.style.marginBottom="0";domElement.style.marginLeft="0";domElement.style.marginRight="0";domElement.style.marginTop="0";}
WebAppStyle.getMainContainerStyle=function(domElement){WebAppStyle.getDefaultStyle(domElement);}
WebAppStyle.getPageContainerStyle=function(domElement){WebAppStyle.getDefaultStyle(domElement);domElement.style.left="auto";domElement.style.top="auto";}
WebAppStyle.getHomePageStyle=function(domElement){}
WebAppStyle.getPageStyle=function(domElement){domElement.style.width="100%";domElement.style.height="100%";}
WebAppStyle.getBgStyle=function(domElement){WebAppStyle.getDefaultStyle(domElement);domElement.style.position="absolute";domElement.style.display="block";domElement.style.top="0";domElement.style.left="0";domElement.style.right="0";domElement.style.bottom="0";domElement.style.width="100%";domElement.style.height="100%";}
WebAppStyle.getHeaderStyle=function(domElement){domElement.style.position="fixed";domElement.style.display="block";domElement.style.minWidth="100%";domElement.style.width="100%";domElement.style.left="0";domElement.style.top="0";}
WebAppStyle.getHeaderTileStyle=function(domElement){WebAppStyle.getHeaderStyle(domElement);domElement.style.position="relative";domElement.style.display="block";domElement.style.top="0";domElement.style.bottom="auto";domElement.style.minWidth="100%";domElement.style.width="100%";domElement.style.height=43+"px";}
WebAppStyle.getHeaderLogoStyle=function(domElement){domElement.style.position="absolute";domElement.style.display="block";domElement.style.top="4px";domElement.style.bottom="auto";domElement.style.left="15px";domElement.style.right="auto";domElement.style.width="44px";}
WebAppStyle.getFooterStyle=function(domElement){domElement.style.position="fixed";domElement.style.display="block";domElement.style.left="0";domElement.style.top="auto";domElement.style.bottom="0";}
WebAppStyle.getFooterMenuStyle=function(domElement){domElement.style.position="fixed";domElement.style.display="block";domElement.style.top="auto";domElement.style.bottom="auto";domElement.style.width="auto";}
WebAppStyle.getFooterTileStyle=function(domElement){WebAppStyle.getHeaderStyle(domElement);domElement.style.position="fixed";domElement.style.display="block";domElement.style.top="auto";domElement.style.bottom="0";domElement.style.minWidth="100%";domElement.style.width="100%";domElement.style.height=48+"px";}
WebAppStyle.getHeaderTextStyle=function(domElement){WebAppStyle.getHeaderStyle(domElement);domElement.style.position="absolute";domElement.style.color="#454545";domElement.style.fontSize="20px";domElement.style.fontWeight="bold";domElement.style.fontStyle="normal";domElement.style.fontFamily="HelveticaNeue,Sans-Serif";domElement.style.textAlign="center";domElement.style.paddingTop="8px";domElement.style.minWidth="100%";domElement.style.width="100%";domElement.style.height=43+"px";domElement.style.verticalAlign="middle";}
WebAppStyle.getBackButtonStyle=function(domElement){WebAppStyle.getHeaderStyle(domElement);domElement.style.position="absolute";domElement.style.paddingTop="6px";domElement.style.paddingLeft="10px";}
WebAppStyle.getBackButtonTextStyle=function(domElement){WebAppStyle.getHeaderStyle(domElement);domElement.style.position="absolute";domElement.style.color="#EEEEEE";domElement.style.fontSize="14px";domElement.style.lineHeight="normal";domElement.style.fontWeight="bold";domElement.style.fontStyle="normal";domElement.style.fontFamily="HelveticaNeue, Sans-Serif";domElement.style.textAlign="center";domElement.style.paddingTop="12px";domElement.style.paddingLeft="30px";}
WebAppStyle.getBackButtonImageStyle=function(domElement){WebAppStyle.getHeaderStyle(domElement);domElement.style.display="inline";domElement.style.position="relative";domElement.style.top="0";domElement.style.left="0";}
WebAppStyle.getTextContentStyle=function(domElement){domElement.style.paddingBottom="8px";domElement.style.paddingLeft="8px";domElement.style.paddingTop="8px";domElement.style.paddingRight="8px";}
WebAppStyle.prototype.__class__=WebAppStyle;StringTools=function(){}
StringTools.__name__=["StringTools"];StringTools.urlEncode=function(s){return encodeURIComponent(s);}
StringTools.urlDecode=function(s){return decodeURIComponent(s.split("+").join(" "));}
StringTools.htmlEscape=function(s){return s.split("&").join("&amp;").split("<").join("&lt;").split(">").join("&gt;");}
StringTools.htmlUnescape=function(s){return s.split("&gt;").join(">").split("&lt;").join("<").split("&amp;").join("&");}
StringTools.startsWith=function(s,start){return s.length>=start.length&&s.substr(0,start.length)==start;}
StringTools.endsWith=function(s,end){var elen=end.length;var slen=s.length;return slen>=elen&&s.substr(slen-elen,elen)==end;}
StringTools.isSpace=function(s,pos){var c=s.charCodeAt(pos);return c>=9&&c<=13||c==32;}
StringTools.ltrim=function(s){var l=s.length;var r=0;while(r<l&&StringTools.isSpace(s,r))r++;if(r>0)return s.substr(r,l-r);else return s;}
StringTools.rtrim=function(s){var l=s.length;var r=0;while(r<l&&StringTools.isSpace(s,l-r-1))r++;if(r>0)return s.substr(0,l-r);else return s;}
StringTools.trim=function(s){return StringTools.ltrim(StringTools.rtrim(s));}
StringTools.rpad=function(s,c,l){var sl=s.length;var cl=c.length;while(sl<l)if(l-sl<cl){s+=c.substr(0,l-sl);sl=l;}else{s+=c;sl+=cl;}
return s;}
StringTools.lpad=function(s,c,l){var ns="";var sl=s.length;if(sl>=l)return s;var cl=c.length;while(sl<l)if(l-sl<cl){ns+=c.substr(0,l-sl);sl=l;}else{ns+=c;sl+=cl;}
return ns+s;}
StringTools.replace=function(s,sub,by){return s.split(sub).join(by);}
StringTools.hex=function(n,digits){var s="";var hexChars="0123456789ABCDEF";do{s=hexChars.charAt(n&15)+s;n>>>=4;}while(n>0);if(digits!=null)while(s.length<digits)s="0"+s;return s;}
StringTools.fastCodeAt=function(s,index){return s.cca(index);}
StringTools.isEOF=function(c){return c!=c;}
StringTools.prototype.__class__=StringTools;EReg=function(r,opt){if(r===$_)return;opt=opt.split("u").join("");this.r=new RegExp(r,opt);}
EReg.__name__=["EReg"];EReg.prototype.r=null;EReg.prototype.match=function(s){this.r.m=this.r.exec(s);this.r.s=s;this.r.l=RegExp.leftContext;this.r.r=RegExp.rightContext;return this.r.m!=null;}
EReg.prototype.matched=function(n){return this.r.m!=null&&n>=0&&n<this.r.m.length?this.r.m[n]:(function($this){var $r;throw"EReg::matched";return $r;}(this));}
EReg.prototype.matchedLeft=function(){if(this.r.m==null)throw"No string matched";if(this.r.l==null)return this.r.s.substr(0,this.r.m.index);return this.r.l;}
EReg.prototype.matchedRight=function(){if(this.r.m==null)throw"No string matched";if(this.r.r==null){var sz=this.r.m.index+this.r.m[0].length;return this.r.s.substr(sz,this.r.s.length-sz);}
return this.r.r;}
EReg.prototype.matchedPos=function(){if(this.r.m==null)throw"No string matched";return{pos:this.r.m.index,len:this.r.m[0].length};}
EReg.prototype.split=function(s){var d="#__delim__#";return s.replace(this.r,d).split(d);}
EReg.prototype.replace=function(s,by){return s.replace(this.r,by);}
EReg.prototype.customReplace=function(s,f){var buf=new StringBuf();while(true){if(!this.match(s))break;buf.add(this.matchedLeft());buf.add(f(this));s=this.matchedRight();}
buf.b[buf.b.length]=s==null?"null":s;return buf.b.join("");}
EReg.prototype.__class__=EReg;Xml=function(p){}
Xml.__name__=["Xml"];Xml.Element=null;Xml.PCData=null;Xml.CData=null;Xml.Comment=null;Xml.DocType=null;Xml.Prolog=null;Xml.Document=null;Xml.parse=function(str){var rules=[Xml.enode,Xml.epcdata,Xml.eend,Xml.ecdata,Xml.edoctype,Xml.ecomment,Xml.eprolog];var nrules=rules.length;var current=Xml.createDocument();var stack=new List();while(str.length>0){var i=0;try{while(i<nrules){var r=rules[i];if(r.match(str)){switch(i){case 0:var x=Xml.createElement(r.matched(1));current.addChild(x);str=r.matchedRight();while(Xml.eattribute.match(str)){x.set(Xml.eattribute.matched(1),Xml.eattribute.matched(3));str=Xml.eattribute.matchedRight();}
if(!Xml.eclose.match(str)){i=nrules;throw"__break__";}
if(Xml.eclose.matched(1)==">"){stack.push(current);current=x;}
str=Xml.eclose.matchedRight();break;case 1:var x=Xml.createPCData(r.matched(0));current.addChild(x);str=r.matchedRight();break;case 2:if(current._children!=null&&current._children.length==0){var e=Xml.createPCData("");current.addChild(e);}
if(r.matched(1)!=current._nodeName||stack.isEmpty()){i=nrules;throw"__break__";}
current=stack.pop();str=r.matchedRight();break;case 3:str=r.matchedRight();if(!Xml.ecdata_end.match(str))throw"End of CDATA section not found";var x=Xml.createCData(Xml.ecdata_end.matchedLeft());current.addChild(x);str=Xml.ecdata_end.matchedRight();break;case 4:var pos=0;var count=0;var old=str;try{while(true){if(!Xml.edoctype_elt.match(str))throw"End of DOCTYPE section not found";var p=Xml.edoctype_elt.matchedPos();pos+=p.pos+p.len;str=Xml.edoctype_elt.matchedRight();switch(Xml.edoctype_elt.matched(0)){case"[":count++;break;case"]":count--;if(count<0)throw"Invalid ] found in DOCTYPE declaration";break;default:if(count==0)throw"__break__";}}}catch(e){if(e!="__break__")throw e;}
var x=Xml.createDocType(old.substr(10,pos-11));current.addChild(x);break;case 5:if(!Xml.ecomment_end.match(str))throw"Unclosed Comment";var p=Xml.ecomment_end.matchedPos();var x=Xml.createComment(str.substr(4,p.pos+p.len-7));current.addChild(x);str=Xml.ecomment_end.matchedRight();break;case 6:var prolog=r.matched(0);var x=Xml.createProlog(prolog.substr(2,prolog.length-4));current.addChild(x);str=r.matchedRight();break;}
throw"__break__";}
i+=1;}}catch(e){if(e!="__break__")throw e;}
if(i==nrules){if(str.length>10)throw"Xml parse error : Unexpected "+str.substr(0,10)+"...";else throw"Xml parse error : Unexpected "+str;}}
if(!stack.isEmpty())throw"Xml parse error : Unclosed "+stack.last().getNodeName();return current;}
Xml.createElement=function(name){var r=new Xml();r.nodeType=Xml.Element;r._children=new Array();r._attributes=new Hash();r.setNodeName(name);return r;}
Xml.createPCData=function(data){var r=new Xml();r.nodeType=Xml.PCData;r.setNodeValue(data);return r;}
Xml.createCData=function(data){var r=new Xml();r.nodeType=Xml.CData;r.setNodeValue(data);return r;}
Xml.createComment=function(data){var r=new Xml();r.nodeType=Xml.Comment;r.setNodeValue(data);return r;}
Xml.createDocType=function(data){var r=new Xml();r.nodeType=Xml.DocType;r.setNodeValue(data);return r;}
Xml.createProlog=function(data){var r=new Xml();r.nodeType=Xml.Prolog;r.setNodeValue(data);return r;}
Xml.createDocument=function(){var r=new Xml();r.nodeType=Xml.Document;r._children=new Array();return r;}
Xml.prototype.nodeType=null;Xml.prototype.nodeName=null;Xml.prototype.nodeValue=null;Xml.prototype.parent=null;Xml.prototype._nodeName=null;Xml.prototype._nodeValue=null;Xml.prototype._attributes=null;Xml.prototype._children=null;Xml.prototype._parent=null;Xml.prototype.getNodeName=function(){if(this.nodeType!=Xml.Element)throw"bad nodeType";return this._nodeName;}
Xml.prototype.setNodeName=function(n){if(this.nodeType!=Xml.Element)throw"bad nodeType";return this._nodeName=n;}
Xml.prototype.getNodeValue=function(){if(this.nodeType==Xml.Element||this.nodeType==Xml.Document)throw"bad nodeType";return this._nodeValue;}
Xml.prototype.setNodeValue=function(v){if(this.nodeType==Xml.Element||this.nodeType==Xml.Document)throw"bad nodeType";return this._nodeValue=v;}
Xml.prototype.getParent=function(){return this._parent;}
Xml.prototype.get=function(att){if(this.nodeType!=Xml.Element)throw"bad nodeType";return this._attributes.get(att);}
Xml.prototype.set=function(att,value){if(this.nodeType!=Xml.Element)throw"bad nodeType";this._attributes.set(att,value);}
Xml.prototype.remove=function(att){if(this.nodeType!=Xml.Element)throw"bad nodeType";this._attributes.remove(att);}
Xml.prototype.exists=function(att){if(this.nodeType!=Xml.Element)throw"bad nodeType";return this._attributes.exists(att);}
Xml.prototype.attributes=function(){if(this.nodeType!=Xml.Element)throw"bad nodeType";return this._attributes.keys();}
Xml.prototype.iterator=function(){if(this._children==null)throw"bad nodetype";return{cur:0,x:this._children,hasNext:function(){return this.cur<this.x.length;},next:function(){return this.x[this.cur++];}};}
Xml.prototype.elements=function(){if(this._children==null)throw"bad nodetype";return{cur:0,x:this._children,hasNext:function(){var k=this.cur;var l=this.x.length;while(k<l){if(this.x[k].nodeType==Xml.Element)break;k+=1;}
this.cur=k;return k<l;},next:function(){var k=this.cur;var l=this.x.length;while(k<l){var n=this.x[k];k+=1;if(n.nodeType==Xml.Element){this.cur=k;return n;}}
return null;}};}
Xml.prototype.elementsNamed=function(name){if(this._children==null)throw"bad nodetype";return{cur:0,x:this._children,hasNext:function(){var k=this.cur;var l=this.x.length;while(k<l){var n=this.x[k];if(n.nodeType==Xml.Element&&n._nodeName==name)break;k++;}
this.cur=k;return k<l;},next:function(){var k=this.cur;var l=this.x.length;while(k<l){var n=this.x[k];k++;if(n.nodeType==Xml.Element&&n._nodeName==name){this.cur=k;return n;}}
return null;}};}
Xml.prototype.firstChild=function(){if(this._children==null)throw"bad nodetype";return this._children[0];}
Xml.prototype.firstElement=function(){if(this._children==null)throw"bad nodetype";var cur=0;var l=this._children.length;while(cur<l){var n=this._children[cur];if(n.nodeType==Xml.Element)return n;cur++;}
return null;}
Xml.prototype.addChild=function(x){if(this._children==null)throw"bad nodetype";if(x._parent!=null)x._parent._children.remove(x);x._parent=this;this._children.push(x);}
Xml.prototype.removeChild=function(x){if(this._children==null)throw"bad nodetype";var b=this._children.remove(x);if(b)x._parent=null;return b;}
Xml.prototype.insertChild=function(x,pos){if(this._children==null)throw"bad nodetype";if(x._parent!=null)x._parent._children.remove(x);x._parent=this;this._children.insert(pos,x);}
Xml.prototype.toString=function(){if(this.nodeType==Xml.PCData)return this._nodeValue;if(this.nodeType==Xml.CData)return"<![CDATA["+this._nodeValue+"]]>";if(this.nodeType==Xml.Comment)return"<!--"+this._nodeValue+"-->";if(this.nodeType==Xml.DocType)return"<!DOCTYPE "+this._nodeValue+">";if(this.nodeType==Xml.Prolog)return"<?"+this._nodeValue+"?>";var s=new StringBuf();if(this.nodeType==Xml.Element){s.b[s.b.length]="<"==null?"null":"<";s.add(this._nodeName);var $it0=this._attributes.keys();while($it0.hasNext()){var k=$it0.next();s.b[s.b.length]=" "==null?"null":" ";s.b[s.b.length]=k==null?"null":k;s.b[s.b.length]="=\""==null?"null":"=\"";s.add(this._attributes.get(k));s.b[s.b.length]="\""==null?"null":"\"";}
if(this._children.length==0){s.b[s.b.length]="/>"==null?"null":"/>";return s.b.join("");}
s.b[s.b.length]=">"==null?"null":">";}
var $it1=this.iterator();while($it1.hasNext()){var x=$it1.next();s.add(x.toString());}
if(this.nodeType==Xml.Element){s.b[s.b.length]="</"==null?"null":"</";s.add(this._nodeName);s.b[s.b.length]=">"==null?"null":">";}
return s.b.join("");}
Xml.prototype.__class__=Xml;Reflect=function(){}
Reflect.__name__=["Reflect"];Reflect.hasField=function(o,field){if(o.hasOwnProperty!=null)return o.hasOwnProperty(field);var arr=Reflect.fields(o);var $it0=arr.iterator();while($it0.hasNext()){var t=$it0.next();if(t==field)return true;}
return false;}
Reflect.field=function(o,field){var v=null;try{v=o[field];}catch(e){}
return v;}
Reflect.setField=function(o,field,value){o[field]=value;}
Reflect.callMethod=function(o,func,args){return func.apply(o,args);}
Reflect.fields=function(o){if(o==null)return new Array();var a=new Array();if(o.hasOwnProperty){for(var i in o)if(o.hasOwnProperty(i))a.push(i);}else{var t;try{t=o.__proto__;}catch(e){t=null;}
if(t!=null)o.__proto__=null;for(var i in o)if(i!="__proto__")a.push(i);if(t!=null)o.__proto__=t;}
return a;}
Reflect.isFunction=function(f){return typeof(f)=="function"&&f.__name__==null;}
Reflect.compare=function(a,b){return a==b?0:a>b?1:-1;}
Reflect.compareMethods=function(f1,f2){if(f1==f2)return true;if(!Reflect.isFunction(f1)||!Reflect.isFunction(f2))return false;return f1.scope==f2.scope&&f1.method==f2.method&&f1.method!=null;}
Reflect.isObject=function(v){if(v==null)return false;var t=typeof(v);return t=="string"||t=="object"&&!v.__enum__||t=="function"&&v.__name__!=null;}
Reflect.deleteField=function(o,f){if(!Reflect.hasField(o,f))return false;delete(o[f]);return true;}
Reflect.copy=function(o){var o2={};var _g=0,_g1=Reflect.fields(o);while(_g<_g1.length){var f=_g1[_g];++_g;o2[f]=Reflect.field(o,f);}
return o2;}
Reflect.makeVarArgs=function(f){return function(){var a=new Array();var _g1=0,_g=arguments.length;while(_g1<_g){var i=_g1++;a.push(arguments[i]);}
return f(a);};}
Reflect.prototype.__class__=Reflect;Navigation=function(container,startPage){if(container===$_)return;this.pagesContainer=container;this.currentPage=startPage;this._previousPages=new Array();this._previousPages.push(startPage);this.pagesContainer.appendChild(startPage);}
Navigation.__name__=["Navigation"];Navigation.prototype.pagesContainer=null;Navigation.prototype.currentPage=null;Navigation.prototype._previousPages=null;Navigation.prototype.goToPreviousPage=function(){this.showPage(this.getPreviousPage());}
Navigation.prototype.getPreviousPage=function(){this._previousPages.pop();var previousPage=this._previousPages[this._previousPages.length-1];if(previousPage==null)return this._previousPages[0];return previousPage;}
Navigation.prototype.addToHistory=function(page){if(page==this._previousPages[0])this._previousPages=[page];else this._previousPages.push(page);}
Navigation.prototype.showPage=function(page){this.pagesContainer.removeChild(this.currentPage);this.pagesContainer.appendChild(page);this.currentPage=page;}
Navigation.prototype.onChangeListCallback=function(cell){if(cell.action=="goToPage"){var page=cell.actionTarget;this.addToHistory(page);this.showPage(page);}else if(cell.action=="goToUrl")this.goToUrl(cell.actionTarget);else if(cell.action=="openUrl")this.openUrl(cell.actionTarget);}
Navigation.prototype.goToUrl=function(url){js.Lib.window.open(url);}
Navigation.prototype.openUrl=function(url){js.Lib.window.open(url,"_self");}
Navigation.prototype.__class__=Navigation;if(typeof haxe=='undefined')haxe={}
haxe.Log=function(){}
haxe.Log.__name__=["haxe","Log"];haxe.Log.trace=function(v,infos){js.Boot.__trace(v,infos);}
haxe.Log.clear=function(){js.Boot.__clear_trace();}
haxe.Log.prototype.__class__=haxe.Log;if(typeof components=='undefined')components={}
if(!components.dataProvider)components.dataProvider={}
components.dataProvider.XmlLoader=function(xmlUrl){if(xmlUrl===$_)return;this.loadXmlFeed(xmlUrl);}
components.dataProvider.XmlLoader.__name__=["components","dataProvider","XmlLoader"];components.dataProvider.XmlLoader.prototype.onLoad=null;components.dataProvider.XmlLoader.prototype.loadXmlFeed=function(xmlUrl){var http=new haxe.Http("http://demos.silexlabs.org/cocktail/simple-webapp/XmlProxy.php?url="+StringTools.urlEncode(xmlUrl));http.onData=$closure(this,"onXmlLoaded");http.onError=$closure(this,"onXmlError");http.request(false);}
components.dataProvider.XmlLoader.prototype.onXmlError=function(msg){haxe.Log.trace("Error while loading XML feed : "+msg,{fileName:"XmlLoader.hx",lineNumber:54,className:"components.dataProvider.XmlLoader",methodName:"onXmlError"});}
components.dataProvider.XmlLoader.prototype.onXmlLoaded=function(xmlString){var xml=Xml.parse(xmlString);if(this.onLoad!=null)this.onLoad(xml);}
components.dataProvider.XmlLoader.prototype.__class__=components.dataProvider.XmlLoader;Utils=function(){}
Utils.__name__=["Utils"];Utils.getContainer=function(){var ret=js.Lib.document.createElement("div");ret.style.display="block";return ret;}
Utils.prototype.__class__=Utils;if(!components.lists)components.lists={}
components.lists.ListBaseUtils=function(){}
components.lists.ListBaseUtils.__name__=["components","lists","ListBaseUtils"];components.lists.ListBaseUtils.__super__=Utils;for(var k in Utils.prototype)components.lists.ListBaseUtils.prototype[k]=Utils.prototype[k];components.lists.ListBaseUtils.createListModel=function(){var richListModel={content:new Array()};return richListModel;}
components.lists.ListBaseUtils.prototype.__class__=components.lists.ListBaseUtils;components.lists.ThumbTextList1Style=function(){}
components.lists.ThumbTextList1Style.__name__=["components","lists","ThumbTextList1Style"];components.lists.ThumbTextList1Style.getListStyle=function(domElement){domElement.style.display="block";domElement.style.position="absolute";domElement.style.marginLeft="0";domElement.style.marginRight="0";domElement.style.marginTop="0";domElement.style.marginBottom="0";domElement.style.paddingLeft="0";domElement.style.paddingRight="0";domElement.style.paddingTop="0";domElement.style.paddingBottom=48+"px";domElement.style.top="43px";}
components.lists.ThumbTextList1Style.getCellStyle=function(domElement){domElement.style.paddingTop="1%";domElement.style.height="200px";}
components.lists.ThumbTextList1Style.getCellInfoBlockStyle=function(domElement){domElement.style.display="inline-block";domElement.style.width="10%";domElement.style.verticalAlign="middle";domElement.style.textAlign="center";}
components.lists.ThumbTextList1Style.getCellNumberStyle=function(domElement,screenResolutionSize){components.lists.ThumbTextList1Style.getCellTextStyle(domElement);var fontSize=12;if(screenResolutionSize==ScreenResolutionSize.small)fontSize=12;else if(screenResolutionSize==ScreenResolutionSize.normal)fontSize=16;else fontSize=20;domElement.style.fontSize=fontSize+"px";domElement.style.fontWeight="bold";domElement.style.color="#989898";domElement.style.textAlign="center";domElement.style.paddingBottom="2%";}
components.lists.ThumbTextList1Style.getCellCommentCountStyle=function(domElement,screenResolutionSize){components.lists.ThumbTextList1Style.getCellTextStyle(domElement);var fontSize=11;if(screenResolutionSize==ScreenResolutionSize.small)fontSize=11;else if(screenResolutionSize==ScreenResolutionSize.normal)fontSize=14;else fontSize=17;domElement.style.fontSize=fontSize+"px";domElement.style.fontWeight="bold";domElement.style.color="#CC3517";domElement.style.textAlign="center";}
components.lists.ThumbTextList1Style.getCellInfoBlockLineStyle=function(domElement,screenResolutionSize){var imageMaxWidth=50;domElement.style.display="block";domElement.style.marginLeft="auto";domElement.style.marginRight="auto";domElement.style.marginTop="auto";domElement.style.marginBottom="auto";domElement.style.paddingBottom="5%";domElement.style.verticalAlign="middle";if(screenResolutionSize==ScreenResolutionSize.large){domElement.style.width=imageMaxWidth+"px";domElement.style.height="2px";}else{domElement.style.maxWidth=imageMaxWidth+"px";domElement.style.width="90%";}}
components.lists.ThumbTextList1Style.getCellInfoBlockImageStyle=function(domElement,screenResolutionSize){domElement.style.display="inline-block";domElement.style.marginLeft="auto";domElement.style.marginRight="auto";domElement.style.marginTop="auto";domElement.style.marginBottom="auto";domElement.style.paddingBottom="2%";domElement.style.verticalAlign="middle";domElement.style.maxWidth="20px";domElement.style.width="50%";if(screenResolutionSize==ScreenResolutionSize.large)domElement.style.width="20px";}
components.lists.ThumbTextList1Style.getCellThumbnailStyle=function(domElement,screenResolutionSize){var imageMaxWidth=200;components.lists.ThumbTextList1Style.getCellStyle(domElement);domElement.style.display="inline";domElement.style.paddingLeft="1%";domElement.style.paddingRight="1%";domElement.style.paddingBottom="1%";domElement.style.verticalAlign="middle";if(screenResolutionSize==ScreenResolutionSize.large){domElement.style.width=imageMaxWidth+"px";domElement.style.height="auto";}else{domElement.style.maxWidth=imageMaxWidth+"px";domElement.style.maxHeight="50%";domElement.style.width="30%";}}
components.lists.ThumbTextList1Style.getCellLineStyle=function(domElement){domElement.style.display="block";domElement.style.width="100%";domElement.style.height="1px";}
components.lists.ThumbTextList1Style.getCellTextBlockStyle=function(domElement){components.lists.ThumbTextList1Style.getCellStyle(domElement);domElement.style.display="inline-block";domElement.style.marginLeft="2%";domElement.style.verticalAlign="middle";domElement.style.width="55%";}
components.lists.ThumbTextList1Style.getCellTextStyle=function(domElement){domElement.style.display="block";domElement.style.color="#202020";domElement.style.fontFamily="HelveticaNeue, Sans-Serif";}
components.lists.ThumbTextList1Style.getCellTitleStyle=function(domElement,screenResolutionSize){components.lists.ThumbTextList1Style.getCellTextStyle(domElement);var fontSize=14;if(screenResolutionSize==ScreenResolutionSize.small)fontSize=14;else if(screenResolutionSize==ScreenResolutionSize.normal)fontSize=16;else fontSize=18;domElement.style.fontSize=fontSize+"px";domElement.style.fontWeight="bold";}
components.lists.ThumbTextList1Style.getCellCommentStyle=function(domElement,screenResolutionSize){components.lists.ThumbTextList1Style.getCellTextStyle(domElement);var fontSize=10;if(screenResolutionSize==ScreenResolutionSize.small)fontSize=10;else if(screenResolutionSize==ScreenResolutionSize.normal)fontSize=11;else fontSize=12;domElement.style.fontSize=fontSize+"px";domElement.style.fontWeight="normal";}
components.lists.ThumbTextList1Style.getCellDescriptionStyle=function(domElement){components.lists.ThumbTextList1Style.getCellTextStyle(domElement);domElement.style.fontSize="14px";domElement.style.fontWeight="bold";}
components.lists.ThumbTextList1Style.getCellMouseOverStyle=function(domElement){}
components.lists.ThumbTextList1Style.getCellMouseOutStyle=function(domElement){}
components.lists.ThumbTextList1Style.getCellMouseDownStyle=function(domElement){}
components.lists.ThumbTextList1Style.getCellMouseUpStyle=function(domElement){}
components.lists.ThumbTextList1Style.prototype.__class__=components.lists.ThumbTextList1Style;StringBuf=function(p){if(p===$_)return;this.b=new Array();}
StringBuf.__name__=["StringBuf"];StringBuf.prototype.add=function(x){this.b[this.b.length]=x==null?"null":x;}
StringBuf.prototype.addSub=function(s,pos,len){this.b[this.b.length]=s.substr(pos,len);}
StringBuf.prototype.addChar=function(c){this.b[this.b.length]=String.fromCharCode(c);}
StringBuf.prototype.toString=function(){return this.b.join("");}
StringBuf.prototype.b=null;StringBuf.prototype.__class__=StringBuf;components.dataProvider.ThumbTextList1Rss=function(){}
components.dataProvider.ThumbTextList1Rss.__name__=["components","dataProvider","ThumbTextList1Rss"];components.dataProvider.ThumbTextList1Rss.rss2Cells=function(rss){var cells=new Array();var channelNode=rss.firstElement().firstElement();var $it0=channelNode.elements();while($it0.hasNext()){var channelChild=$it0.next();if(channelChild.getNodeName()=="item"){var cell={content:Dynamic,action:"",actionTarget:""};var cellContent={imagePath:"",title:"",comment:"Posted ",description:"",commentCount:"0"};var $it1=channelChild.elements();while($it1.hasNext()){var itemParam=$it1.next();if(itemParam.getNodeName()=="post_thumbnail")cellContent.thumbnail=itemParam.firstChild().getNodeValue();if(itemParam.getNodeName()=="post_images"){if(!Reflect.hasField(cellContent,"thumbnail")||Reflect.field(cellContent,"thumbnail")==""){var $it2=itemParam.elements();while($it2.hasNext()){var elements=$it2.next();cellContent.thumbnail=itemParam.firstElement().firstChild().getNodeValue();break;}}}
if(itemParam.getNodeName()=="title"){var title=itemParam.firstChild().getNodeValue();var index=title.indexOf("Name");if(index!=-1)title=title.substr(0,index);title=StringTools.rtrim(title);cellContent.title=title;}
if(itemParam.getNodeName()=="dc:creator")cellContent.comment=cellContent.comment+"by "+itemParam.firstChild().getNodeValue()+" ";if(itemParam.getNodeName()=="pubDate")cellContent.comment=cellContent.comment+"on "+itemParam.firstChild().getNodeValue().substr(0,16)+" ";if(itemParam.getNodeName()=="description"){var text=itemParam.firstChild().getNodeValue();var toRemove=["Online Demo","Online demo","Description :"];var _g=0;while(_g<toRemove.length){var string=toRemove[_g];++_g;text=StringTools.replace(text,string,"");}
text=StringTools.ltrim(text);cellContent.description=text;}
if(itemParam.getNodeName()=="comment_count")cellContent.commentCount=itemParam.firstChild().getNodeValue();if(itemParam.getNodeName()=="guid"){cell.action="goToUrl";cell.actionTarget=itemParam.firstChild().getNodeValue();}}
cell.content=cellContent;cells.push(cell);}}
return cells;}
components.dataProvider.ThumbTextList1Rss.prototype.__class__=components.dataProvider.ThumbTextList1Rss;WebApp=function(p){if(p===$_)return;this._body=js.Lib.document.body;WebAppStyle.getBodyStyle(this._body);this.drawInterface();}
WebApp.__name__=["WebApp"];WebApp.main=function(){new WebApp();}
WebApp.prototype._body=null;WebApp.prototype._mainContainer=null;WebApp.prototype.drawInterface=function(){var applicationStructure=new ApplicationStructure();this._mainContainer=applicationStructure.pagesContainer;WebAppStyle.getMainContainerStyle(this._mainContainer);this._body.appendChild(this._mainContainer);}
WebApp.prototype.__class__=WebApp;components.lists.ListBase=function(list,listStyle){if(list===$_)return;this._listData=list.content;this._currentCellIndex=0;this._selectedCellData=this._listData[this._currentCellIndex];this._htmlDom=js.Lib.document.createElement("ul");this.createListDOM(list,listStyle);listStyle.list(this._htmlDom);this.selectCell(this._selectedCellDOM);}
components.lists.ListBase.__name__=["components","lists","ListBase"];components.lists.ListBase.prototype.onChange=null;components.lists.ListBase.prototype._listData=null;components.lists.ListBase.prototype._currentCellIndex=null;components.lists.ListBase.prototype._selectedCellData=null;components.lists.ListBase.prototype._selectedCellDOM=null;components.lists.ListBase.prototype._htmlDom=null;components.lists.ListBase.prototype.htmlDom=null;components.lists.ListBase.prototype.createListDOM=function(list,listStyle){var content=Utils.getContainer();var cellData;var _g=0,_g1=list.content;while(_g<_g1.length){var cellData1=_g1[_g];++_g;var cell=this.createCellDOM(cellData1,listStyle);this._htmlDom.appendChild(cell);if(this._currentCellIndex==0)this._selectedCellDOM=cell;this._currentCellIndex++;}
this._currentCellIndex=0;}
components.lists.ListBase.prototype.createCellDOM=function(cellData,listStyle){var cell=js.Lib.document.createElement("li");var cellLink=js.Lib.document.createElement("a");cellLink.style.textAlign="center";if(cellData.action=="openUrl"||cellData.action=="goToUrl"){cellLink.href=cellData.actionTarget;cellLink.target="blank";}else{var onCellMouseUpDelegate=$closure(this,"onCellSelected");cell.onmouseup=function(mouseEventData){onCellMouseUpDelegate(cell,cellData);};}
listStyle.cell(cell);var cellContent=this.getCellData(cellData.content,listStyle);var _g=0;while(_g<cellContent.length){var container=cellContent[_g];++_g;cellLink.appendChild(container);}
cell.appendChild(cellLink);return cell;}
components.lists.ListBase.prototype.getCellData=function(cellData,listStyle){var cellContent=new Array();return cellContent;}
components.lists.ListBase.prototype.onCellSelected=function(cell,cellData){if(this.onChange!=null)this.onChange(cellData);this.selectCell(cell);}
components.lists.ListBase.prototype.selectCell=function(cell){this._selectedCellDOM=cell;}
components.lists.ListBase.prototype.onListKeyDown=function(key){}
components.lists.ListBase.prototype.selectNextCell=function(){}
components.lists.ListBase.prototype.selectPreviousCell=function(){}
components.lists.ListBase.prototype.get_htmlDom=function(){return this._htmlDom;}
components.lists.ListBase.prototype.__class__=components.lists.ListBase;components.lists.ThumbTextList1=function(list,listStyle){if(list===$_)return;var screenResolution=new ScreenResolution();this.screenResolutionSize=screenResolution.size;components.lists.ListBase.call(this,list,listStyle);}
components.lists.ThumbTextList1.__name__=["components","lists","ThumbTextList1"];components.lists.ThumbTextList1.__super__=components.lists.ListBase;for(var k in components.lists.ListBase.prototype)components.lists.ThumbTextList1.prototype[k]=components.lists.ListBase.prototype[k];components.lists.ThumbTextList1.prototype.screenResolutionSize=null;components.lists.ThumbTextList1.prototype.getCellData=function(cellData,listStyle){var cellContent=new Array();var cellInfoBlockContainer=Utils.getContainer();listStyle.cellInfoBlock(cellInfoBlockContainer);cellContent.push(cellInfoBlockContainer);var cellNumberContainer=Utils.getContainer();var textElement=js.Lib.document.createTextNode(Std.string(this._currentCellIndex+1));cellNumberContainer.appendChild(textElement);listStyle.cellNumber(cellNumberContainer,this.screenResolutionSize);cellInfoBlockContainer.appendChild(cellNumberContainer);var celldotsLine=js.Lib.document.createElement("img");listStyle.cellInfoBlockLine(celldotsLine,this.screenResolutionSize);cellInfoBlockContainer.appendChild(celldotsLine);celldotsLine.src="images/dotsLine.png";var cellCommentImage=js.Lib.document.createElement("img");listStyle.cellInfoBlockImage(cellCommentImage,this.screenResolutionSize);cellInfoBlockContainer.appendChild(cellCommentImage);cellCommentImage.src="images/bubble.png";if(cellData.commentCount!=""&&cellData.commentCount!=null){var cellCommentCountContainer=Utils.getContainer();var textElement1=js.Lib.document.createTextNode(cellData.commentCount);cellCommentCountContainer.appendChild(textElement1);listStyle.cellCommentCount(cellCommentCountContainer,this.screenResolutionSize);cellInfoBlockContainer.appendChild(cellCommentCountContainer);}
if(cellData.thumbnail!=""&&cellData.thumbnail!=null){var cellImage=js.Lib.document.createElement("img");listStyle.cellThumbnail(cellImage,this.screenResolutionSize);cellContent.push(cellImage);cellImage.src=cellData.thumbnail;}
var cellTextBlockContainer=Utils.getContainer();listStyle.cellTextBlock(cellTextBlockContainer);cellContent.push(cellTextBlockContainer);if(cellData.title!=""&&cellData.title!=null){var cellTitleContainer=Utils.getContainer();var textElement1=js.Lib.document.createTextNode(cellData.title);cellTitleContainer.appendChild(textElement1);listStyle.cellTitle(cellTitleContainer,this.screenResolutionSize);cellTextBlockContainer.appendChild(cellTitleContainer);}
if(cellData.comment!=""&&cellData.comment!=null){var cellCommentContainer=Utils.getContainer();var textElement1=js.Lib.document.createTextNode(cellData.comment);cellCommentContainer.appendChild(textElement1);listStyle.cellComment(cellCommentContainer,this.screenResolutionSize);cellTextBlockContainer.appendChild(cellCommentContainer);}
if(this.screenResolutionSize==ScreenResolutionSize.large){if(cellData.description!=""&&cellData.description!=null){var textLength;if(this.screenResolutionSize==ScreenResolutionSize.normal)textLength=95;else textLength=200;var cellDescriptionContainer=Utils.getContainer();var shortenedText=cellData.description.substr(0,textLength)+"...";var textElement1=js.Lib.document.createTextNode(shortenedText);cellDescriptionContainer.appendChild(textElement1);listStyle.cellDescription(cellDescriptionContainer);cellTextBlockContainer.appendChild(cellDescriptionContainer);}}
var line=js.Lib.document.createElement("img");listStyle.cellLine(line);cellContent.push(line);line.src="images/greyPixel.png";return cellContent;}
components.lists.ThumbTextList1.prototype.__class__=components.lists.ThumbTextList1;ScreenResolutionSize={__ename__:["ScreenResolutionSize"],__constructs__:["small","normal","large"]}
ScreenResolutionSize.small=["small",0];ScreenResolutionSize.small.toString=$estr;ScreenResolutionSize.small.__enum__=ScreenResolutionSize;ScreenResolutionSize.normal=["normal",1];ScreenResolutionSize.normal.toString=$estr;ScreenResolutionSize.normal.__enum__=ScreenResolutionSize;ScreenResolutionSize.large=["large",2];ScreenResolutionSize.large.toString=$estr;ScreenResolutionSize.large.__enum__=ScreenResolutionSize;ScreenResolution=function(p){if(p===$_)return;var viewport=js.Lib.window;if(viewport.innerWidth<400)this.size=ScreenResolutionSize.small;else if(viewport.innerWidth<600)this.size=ScreenResolutionSize.normal;else this.size=ScreenResolutionSize.large;}
ScreenResolution.__name__=["ScreenResolution"];ScreenResolution.prototype.size=null;ScreenResolution.prototype.__class__=ScreenResolution;IntIter=function(min,max){if(min===$_)return;this.min=min;this.max=max;}
IntIter.__name__=["IntIter"];IntIter.prototype.min=null;IntIter.prototype.max=null;IntIter.prototype.hasNext=function(){return this.min<this.max;}
IntIter.prototype.next=function(){return this.min++;}
IntIter.prototype.__class__=IntIter;Std=function(){}
Std.__name__=["Std"];Std["is"]=function(v,t){return js.Boot.__instanceof(v,t);}
Std.string=function(s){return js.Boot.__string_rec(s,"");}
Std["int"]=function(x){if(x<0)return Math.ceil(x);return Math.floor(x);}
Std.parseInt=function(x){var v=parseInt(x,10);if(v==0&&x.charCodeAt(1)==120)v=parseInt(x);if(isNaN(v))return null;return v;}
Std.parseFloat=function(x){return parseFloat(x);}
Std.random=function(x){return Math.floor(Math.random()*x);}
Std.prototype.__class__=Std;components.lists.AppListStyle=function(){}
components.lists.AppListStyle.__name__=["components","lists","AppListStyle"];components.lists.AppListStyle.getListStyle=function(domElement){domElement.style.position="fixed";domElement.style.display="inline-block";domElement.style.marginLeft="0";domElement.style.marginRight="0";domElement.style.marginTop="0";domElement.style.marginBottom="0";domElement.style.paddingLeft="0";domElement.style.paddingRight="0";domElement.style.paddingTop="0";domElement.style.paddingBottom="0";domElement.style.top="auto";domElement.style.bottom="0";domElement.style.left="auto";domElement.style.right="auto";domElement.style.minWidth="100%";domElement.style.width="100%";domElement.style.height=48+"px";domElement.style.textAlign="center";}
components.lists.AppListStyle.getCellStyle=function(domElement){domElement.style.display="inline-block";domElement.style.marginLeft="0";domElement.style.marginRight="0";domElement.style.marginTop="2px";domElement.style.width=62+"px";domElement.style.height=43+"px";domElement.style.color="#BDBDCE";}
components.lists.AppListStyle.getCellSelectedStyle=function(domElement){domElement.style.position="absolute";domElement.style.display="block";domElement.style.marginLeft="0";domElement.style.marginRight="0";domElement.style.marginTop="0";domElement.style.marginBottom="0";domElement.style.paddingLeft="0";domElement.style.paddingRight="0";domElement.style.paddingTop="0";domElement.style.paddingBottom="0";domElement.style.width=62+"px";domElement.style.height=43+"px";domElement.style.bottom="2px";}
components.lists.AppListStyle.getCellImageStyle=function(domElement){domElement.style.display="block";domElement.style.marginLeft="auto";domElement.style.marginRight="auto";domElement.style.height="31px";domElement.style.marginBottom="0";}
components.lists.AppListStyle.getCellTextStyle=function(domElement){domElement.style.display="block";domElement.style.marginTop="0";domElement.style.color="#999999";domElement.style.fontFamily="HelveticaNeue, Sans-Serif";domElement.style.fontSize="10px";domElement.style.fontWeight="bold";domElement.style.textAlign="center";}
components.lists.AppListStyle.getCellMouseOverStyle=function(domElement){}
components.lists.AppListStyle.getCellMouseOutStyle=function(domElement){}
components.lists.AppListStyle.getCellMouseDownStyle=function(domElement){}
components.lists.AppListStyle.getCellMouseUpStyle=function(domElement){}
components.lists.AppListStyle.prototype.__class__=components.lists.AppListStyle;List=function(p){if(p===$_)return;this.length=0;}
List.__name__=["List"];List.prototype.h=null;List.prototype.q=null;List.prototype.length=null;List.prototype.add=function(item){var x=[item];if(this.h==null)this.h=x;else this.q[1]=x;this.q=x;this.length++;}
List.prototype.push=function(item){var x=[item,this.h];this.h=x;if(this.q==null)this.q=x;this.length++;}
List.prototype.first=function(){return this.h==null?null:this.h[0];}
List.prototype.last=function(){return this.q==null?null:this.q[0];}
List.prototype.pop=function(){if(this.h==null)return null;var x=this.h[0];this.h=this.h[1];if(this.h==null)this.q=null;this.length--;return x;}
List.prototype.isEmpty=function(){return this.h==null;}
List.prototype.clear=function(){this.h=null;this.q=null;this.length=0;}
List.prototype.remove=function(v){var prev=null;var l=this.h;while(l!=null){if(l[0]==v){if(prev==null)this.h=l[1];else prev[1]=l[1];if(this.q==l)this.q=prev;this.length--;return true;}
prev=l;l=l[1];}
return false;}
List.prototype.iterator=function(){return{h:this.h,hasNext:function(){return this.h!=null;},next:function(){if(this.h==null)return null;var x=this.h[0];this.h=this.h[1];return x;}};}
List.prototype.toString=function(){var s=new StringBuf();var first=true;var l=this.h;s.b[s.b.length]="{"==null?"null":"{";while(l!=null){if(first)first=false;else s.b[s.b.length]=", "==null?"null":", ";s.add(Std.string(l[0]));l=l[1];}
s.b[s.b.length]="}"==null?"null":"}";return s.b.join("");}
List.prototype.join=function(sep){var s=new StringBuf();var first=true;var l=this.h;while(l!=null){if(first)first=false;else s.b[s.b.length]=sep==null?"null":sep;s.add(l[0]);l=l[1];}
return s.b.join("");}
List.prototype.filter=function(f){var l2=new List();var l=this.h;while(l!=null){var v=l[0];l=l[1];if(f(v))l2.add(v);}
return l2;}
List.prototype.map=function(f){var b=new List();var l=this.h;while(l!=null){var v=l[0];l=l[1];b.add(f(v));}
return b;}
List.prototype.__class__=List;components.lists.AppList=function(list,listStyle){if(list===$_)return;this._selectedMenuItemImage=js.Lib.document.createElement("a");listStyle.cellSelected(this._selectedMenuItemImage);this._selectedMenuItemImage.src="images/selectedMenuItem.png";components.lists.ListBase.call(this,list,listStyle);}
components.lists.AppList.__name__=["components","lists","AppList"];components.lists.AppList.__super__=components.lists.ListBase;for(var k in components.lists.ListBase.prototype)components.lists.AppList.prototype[k]=components.lists.ListBase.prototype[k];components.lists.AppList.prototype._selectedMenuItemImage=null;components.lists.AppList.prototype.createListDOM=function(list,listStyle){components.lists.ListBase.prototype.createListDOM.call(this,list,listStyle);}
components.lists.AppList.prototype.getCellData=function(cellData,listStyle){var cellContent=new Array();if(cellData.icon!=""&&cellData.icon!=null){var cellImage=js.Lib.document.createElement("img");listStyle.cellIcon(cellImage);cellContent.push(cellImage);cellImage.src=cellData.icon;}
if(cellData.title!=""&&cellData.title!=null){var cellTitleContainer=Utils.getContainer();var textElement=js.Lib.document.createTextNode(cellData.title);cellTitleContainer.appendChild(textElement);listStyle.cellTitle(cellTitleContainer);cellContent.push(cellTitleContainer);}
return cellContent;}
components.lists.AppList.prototype.selectCell=function(cell){components.lists.ListBase.prototype.selectCell.call(this,cell);cell.appendChild(this._selectedMenuItemImage);}
components.lists.AppList.prototype.onListKeyDown=function(key){if(key.keyCode=="39")components.lists.ListBase.prototype.selectNextCell.call(this);else if(key.keyCode=="37")components.lists.ListBase.prototype.selectPreviousCell.call(this);}
components.lists.AppList.prototype.__class__=components.lists.AppList;Constants=function(){}
Constants.__name__=["Constants"];Constants.prototype.__class__=Constants;haxe.Http=function(url){if(url===$_)return;this.url=url;this.headers=new Hash();this.params=new Hash();this.async=true;}
haxe.Http.__name__=["haxe","Http"];haxe.Http.requestUrl=function(url){var h=new haxe.Http(url);h.async=false;var r=null;h.onData=function(d){r=d;};h.onError=function(e){throw e;};h.request(false);return r;}
haxe.Http.prototype.url=null;haxe.Http.prototype.async=null;haxe.Http.prototype.postData=null;haxe.Http.prototype.headers=null;haxe.Http.prototype.params=null;haxe.Http.prototype.setHeader=function(header,value){this.headers.set(header,value);}
haxe.Http.prototype.setParameter=function(param,value){this.params.set(param,value);}
haxe.Http.prototype.setPostData=function(data){this.postData=data;}
haxe.Http.prototype.request=function(post){var me=this;var r=new js.XMLHttpRequest();var onreadystatechange=function(){if(r.readyState!=4)return;var s=(function($this){var $r;try{$r=r.status;}catch(e){$r=null;}
return $r;}(this));if(s==undefined)s=null;if(s!=null)me.onStatus(s);if(s!=null&&s>=200&&s<400)me.onData(r.responseText);else switch(s){case null:case undefined:me.onError("Failed to connect or resolve host");break;case 12029:me.onError("Failed to connect to host");break;case 12007:me.onError("Unknown host");break;default:me.onError("Http Error #"+r.status);}};if(this.async)r.onreadystatechange=onreadystatechange;var uri=this.postData;if(uri!=null)post=true;else{var $it0=this.params.keys();while($it0.hasNext()){var p=$it0.next();if(uri==null)uri="";else uri+="&";uri+=StringTools.urlDecode(p)+"="+StringTools.urlEncode(this.params.get(p));}}
try{if(post)r.open("POST",this.url,this.async);else if(uri!=null){var question=this.url.split("?").length<=1;r.open("GET",this.url+(question?"?":"&")+uri,this.async);uri=null;}else r.open("GET",this.url,this.async);}catch(e){this.onError(e.toString());return;}
if(this.headers.get("Content-Type")==null&&post&&this.postData==null)r.setRequestHeader("Content-Type","application/x-www-form-urlencoded");var $it1=this.headers.keys();while($it1.hasNext()){var h=$it1.next();r.setRequestHeader(h,this.headers.get(h));}
r.send(uri);if(!this.async)onreadystatechange();}
haxe.Http.prototype.onData=function(data){}
haxe.Http.prototype.onError=function(msg){}
haxe.Http.prototype.onStatus=function(status){}
haxe.Http.prototype.__class__=haxe.Http;if(typeof js=='undefined')js={}
js.Lib=function(){}
js.Lib.__name__=["js","Lib"];js.Lib.isIE=null;js.Lib.isOpera=null;js.Lib.document=null;js.Lib.window=null;js.Lib.alert=function(v){alert(js.Boot.__string_rec(v,""));}
js.Lib.eval=function(code){return eval(code);}
js.Lib.setErrorHandler=function(f){js.Lib.onerror=f;}
js.Lib.prototype.__class__=js.Lib;js.Boot=function(){}
js.Boot.__name__=["js","Boot"];js.Boot.__unhtml=function(s){return s.split("&").join("&amp;").split("<").join("&lt;").split(">").join("&gt;");}
js.Boot.__trace=function(v,i){var msg=i!=null?i.fileName+":"+i.lineNumber+": ":"";msg+=js.Boot.__unhtml(js.Boot.__string_rec(v,""))+"<br/>";var d=document.getElementById("haxe:trace");if(d==null)alert("No haxe:trace element defined\n"+msg);else d.innerHTML+=msg;}
js.Boot.__clear_trace=function(){var d=document.getElementById("haxe:trace");if(d!=null)d.innerHTML="";}
js.Boot.__closure=function(o,f){var m=o[f];if(m==null)return null;var f1=function(){return m.apply(o,arguments);};f1.scope=o;f1.method=m;return f1;}
js.Boot.__string_rec=function(o,s){if(o==null)return"null";if(s.length>=5)return"<...>";var t=typeof(o);if(t=="function"&&(o.__name__!=null||o.__ename__!=null))t="object";switch(t){case"object":if(o instanceof Array){if(o.__enum__!=null){if(o.length==2)return o[0];var str=o[0]+"(";s+="\t";var _g1=2,_g=o.length;while(_g1<_g){var i=_g1++;if(i!=2)str+=","+js.Boot.__string_rec(o[i],s);else str+=js.Boot.__string_rec(o[i],s);}
return str+")";}
var l=o.length;var i;var str="[";s+="\t";var _g=0;while(_g<l){var i1=_g++;str+=(i1>0?",":"")+js.Boot.__string_rec(o[i1],s);}
str+="]";return str;}
var tostr;try{tostr=o.toString;}catch(e){return"???";}
if(tostr!=null&&tostr!=Object.toString){var s2=o.toString();if(s2!="[object Object]")return s2;}
var k=null;var str="{\n";s+="\t";var hasp=o.hasOwnProperty!=null;for(var k in o){;if(hasp&&!o.hasOwnProperty(k)){continue;}
if(k=="prototype"||k=="__class__"||k=="__super__"||k=="__interfaces__"){continue;}
if(str.length!=2)str+=", \n";str+=s+k+" : "+js.Boot.__string_rec(o[k],s);}
s=s.substring(1);str+="\n"+s+"}";return str;case"function":return"<function>";case"string":return o;default:return String(o);}}
js.Boot.__interfLoop=function(cc,cl){if(cc==null)return false;if(cc==cl)return true;var intf=cc.__interfaces__;if(intf!=null){var _g1=0,_g=intf.length;while(_g1<_g){var i=_g1++;var i1=intf[i];if(i1==cl||js.Boot.__interfLoop(i1,cl))return true;}}
return js.Boot.__interfLoop(cc.__super__,cl);}
js.Boot.__instanceof=function(o,cl){try{if(o instanceof cl){if(cl==Array)return o.__enum__==null;return true;}
if(js.Boot.__interfLoop(o.__class__,cl))return true;}catch(e){if(cl==null)return false;}
switch(cl){case Int:return Math.ceil(o%2147483648.0)===o;case Float:return typeof(o)=="number";case Bool:return o===true||o===false;case String:return typeof(o)=="string";case Dynamic:return true;default:if(o==null)return false;return o.__enum__==cl||cl==Class&&o.__name__!=null||cl==Enum&&o.__ename__!=null;}}
js.Boot.__init=function(){js.Lib.isIE=typeof document!='undefined'&&document.all!=null&&typeof window!='undefined'&&window.opera==null;js.Lib.isOpera=typeof window!='undefined'&&window.opera!=null;Array.prototype.copy=Array.prototype.slice;Array.prototype.insert=function(i,x){this.splice(i,0,x);};Array.prototype.remove=Array.prototype.indexOf?function(obj){var idx=this.indexOf(obj);if(idx==-1)return false;this.splice(idx,1);return true;}:function(obj){var i=0;var l=this.length;while(i<l){if(this[i]==obj){this.splice(i,1);return true;}
i++;}
return false;};Array.prototype.iterator=function(){return{cur:0,arr:this,hasNext:function(){return this.cur<this.arr.length;},next:function(){return this.arr[this.cur++];}};};if(String.prototype.cca==null)String.prototype.cca=String.prototype.charCodeAt;String.prototype.charCodeAt=function(i){var x=this.cca(i);if(x!=x)return null;return x;};var oldsub=String.prototype.substr;String.prototype.substr=function(pos,len){if(pos!=null&&pos!=0&&len!=null&&len<0)return"";if(len==null)len=this.length;if(pos<0){pos=this.length+pos;if(pos<0)pos=0;}else if(len<0)len=this.length+len-pos;return oldsub.apply(this,[pos,len]);};$closure=js.Boot.__closure;}
js.Boot.prototype.__class__=js.Boot;ApplicationStructure=function(p){if(p===$_)return;this.pagesContainer=Utils.getContainer();this.createAllPages();}
ApplicationStructure.__name__=["ApplicationStructure"];ApplicationStructure.prototype.pagesContainer=null;ApplicationStructure.prototype.navigation=null;ApplicationStructure.prototype._footer=null;ApplicationStructure.prototype._page1=null;ApplicationStructure.prototype._page2=null;ApplicationStructure.prototype._page3=null;ApplicationStructure.prototype._page4=null;ApplicationStructure.prototype._page5=null;ApplicationStructure.prototype.createAllPages=function(){var pluginsRss=new components.dataProvider.XmlLoader("http://www.silexlabs.org/feed/ep_posts_small/?cat=5318&format=rss2");pluginsRss.onLoad=$closure(this,"onPage1RssLoad");var blogRss=new components.dataProvider.XmlLoader("http://www.silexlabs.org/feed/ep_posts_small/?cat=358&format=rss2");blogRss.onLoad=$closure(this,"onPage2RssLoad");var themesRss=new components.dataProvider.XmlLoader("http://www.silexlabs.org/feed/ep_posts_small/?cat=642&format=rss2");themesRss.onLoad=$closure(this,"onPage3RssLoad");var themesRss1=new components.dataProvider.XmlLoader("http://www.silexlabs.org/feed/ep_posts_small/?cat=646&format=rss2");themesRss1.onLoad=$closure(this,"onPage4RssLoad");var pluginsRss1=new components.dataProvider.XmlLoader("http://www.silexlabs.org/feed/ep_posts_small/?cat=657&format=rss2");pluginsRss1.onLoad=$closure(this,"onPage5RssLoad");}
ApplicationStructure.prototype.onPage1RssLoad=function(rss){var cells=components.dataProvider.ThumbTextList1Rss.rss2Cells(rss);this._page2=this.createHeaderListPage("Silex Labs",cells);this.navigation=new Navigation(this.pagesContainer,this._page2);}
ApplicationStructure.prototype.onPage2RssLoad=function(rss){var cells=components.dataProvider.ThumbTextList1Rss.rss2Cells(rss);this._page1=this.createHeaderListPage("amfPHP",cells);}
ApplicationStructure.prototype.onPage3RssLoad=function(rss){var cells=components.dataProvider.ThumbTextList1Rss.rss2Cells(rss);this._page3=this.createHeaderListPage("Silex",cells);}
ApplicationStructure.prototype.onPage4RssLoad=function(rss){var cells=components.dataProvider.ThumbTextList1Rss.rss2Cells(rss);this._page4=this.createHeaderListPage("Themes",cells);}
ApplicationStructure.prototype.onPage5RssLoad=function(rss){var me=this;var cells=components.dataProvider.ThumbTextList1Rss.rss2Cells(rss);this._page5=this.createHeaderListPage("Plugins",cells);this._footer=this.createFooterMenu();this.pagesContainer.appendChild(this._footer);var resetFooterStyle=function(event){me.pagesContainer.removeChild(me._footer);me.pagesContainer.appendChild(me._footer);};js.Lib.window.onscroll=resetFooterStyle;js.Lib.window.onresize=resetFooterStyle;resetFooterStyle(null);js.Lib.document.onkeydown=$closure(this,"onKeyDownPages");}
ApplicationStructure.prototype.createHeaderListPage=function(title,cellDataArray){var page=Utils.getContainer();var header=this.createHeader(title);var list=this.createThumbList(cellDataArray);list.onChange=$closure(this,"onChangeListCallback");page.appendChild(list.get_htmlDom());page.appendChild(header);WebAppStyle.getPageStyle(page);return page;}
ApplicationStructure.prototype.createHeader=function(title){var header=Utils.getContainer();var headerTile=js.Lib.document.createElement("img");WebAppStyle.getHeaderTileStyle(headerTile);var headerTilePath="images/header.jpg";headerTile.src=headerTilePath;header.appendChild(headerTile);var headerLogo=js.Lib.document.createElement("img");WebAppStyle.getHeaderLogoStyle(headerLogo);var headerLogoPath="images/silex-labs.png";headerLogo.src=headerLogoPath;header.appendChild(headerLogo);var headerTitle=js.Lib.document.createTextNode(title);var headerTitleContainer=Utils.getContainer();headerTitleContainer.appendChild(headerTitle);WebAppStyle.getHeaderTextStyle(headerTitleContainer);header.appendChild(headerTitleContainer);WebAppStyle.getHeaderStyle(header);return header;}
ApplicationStructure.prototype.createFooterMenu=function(){var container=Utils.getContainer();WebAppStyle.getFooterStyle(container);var tile=js.Lib.document.createElement("img");var headerTilePath="images/footer.jpg";WebAppStyle.getFooterTileStyle(tile);tile.src=headerTilePath;container.appendChild(tile);var cells=new Array();cells.push({content:{icon:"images/menu3.png",title:"Silex Labs"},action:"goToPage",actionTarget:this._page2});cells.push({content:{icon:"images/menu3.png",title:"amfPHP"},action:"goToPage",actionTarget:this._page1});cells.push({content:{icon:"images/menu3.png",title:"Silex"},action:"goToPage",actionTarget:this._page3});cells.push({content:{icon:"images/menu2.png",title:"Themes"},action:"goToPage",actionTarget:this._page4});cells.push({content:{icon:"images/menu1.png",title:"Plugins"},action:"goToPage",actionTarget:this._page5});var menuList=this.createAppList(cells);menuList.onChange=$closure(this,"onChangeListCallback");container.appendChild(menuList.get_htmlDom());return container;}
ApplicationStructure.prototype.createThumbList=function(content){var listData=components.lists.ListBaseUtils.createListModel();listData.content=content;var listStyle={list:components.lists.ThumbTextList1Style.getListStyle,cell:components.lists.ThumbTextList1Style.getCellStyle,cellInfoBlock:components.lists.ThumbTextList1Style.getCellInfoBlockStyle,cellNumber:components.lists.ThumbTextList1Style.getCellNumberStyle,cellInfoBlockLine:components.lists.ThumbTextList1Style.getCellInfoBlockLineStyle,cellInfoBlockImage:components.lists.ThumbTextList1Style.getCellInfoBlockImageStyle,cellCommentCount:components.lists.ThumbTextList1Style.getCellCommentCountStyle,cellThumbnail:components.lists.ThumbTextList1Style.getCellThumbnailStyle,cellTextBlock:components.lists.ThumbTextList1Style.getCellTextBlockStyle,cellTitle:components.lists.ThumbTextList1Style.getCellTitleStyle,cellComment:components.lists.ThumbTextList1Style.getCellCommentStyle,cellDescription:components.lists.ThumbTextList1Style.getCellDescriptionStyle,cellLine:components.lists.ThumbTextList1Style.getCellLineStyle,cellMouseOver:components.lists.ThumbTextList1Style.getCellMouseOverStyle,cellMouseOut:components.lists.ThumbTextList1Style.getCellMouseOutStyle,cellMouseDown:components.lists.ThumbTextList1Style.getCellMouseDownStyle,cellMouseUp:components.lists.ThumbTextList1Style.getCellMouseUpStyle};var list=new components.lists.ThumbTextList1(listData,listStyle);return list;}
ApplicationStructure.prototype.createAppList=function(content){var listData=components.lists.ListBaseUtils.createListModel();listData.content=content;var listStyle={list:components.lists.AppListStyle.getListStyle,cell:components.lists.AppListStyle.getCellStyle,cellSelected:components.lists.AppListStyle.getCellSelectedStyle,cellIcon:components.lists.AppListStyle.getCellImageStyle,cellTitle:components.lists.AppListStyle.getCellTextStyle,cellMouseOver:components.lists.AppListStyle.getCellMouseOverStyle,cellMouseOut:components.lists.AppListStyle.getCellMouseOutStyle,cellMouseDown:components.lists.AppListStyle.getCellMouseDownStyle,cellMouseUp:components.lists.AppListStyle.getCellMouseUpStyle};var list=new components.lists.AppList(listData,listStyle);return list;}
ApplicationStructure.prototype.goToPreviousPage=function(mouseEvent){this.navigation.goToPreviousPage();}
ApplicationStructure.prototype.onChangeListCallback=function(cell){this.navigation.onChangeListCallback(cell);}
ApplicationStructure.prototype.onKeyDownPages=function(key){}
ApplicationStructure.prototype.__class__=ApplicationStructure;Hash=function(p){if(p===$_)return;this.h={}
if(this.h.__proto__!=null){this.h.__proto__=null;delete(this.h.__proto__);}}
Hash.__name__=["Hash"];Hash.prototype.h=null;Hash.prototype.set=function(key,value){this.h["$"+key]=value;}
Hash.prototype.get=function(key){return this.h["$"+key];}
Hash.prototype.exists=function(key){try{key="$"+key;return this.hasOwnProperty.call(this.h,key);}catch(e){for(var i in this.h)if(i==key)return true;return false;}}
Hash.prototype.remove=function(key){if(!this.exists(key))return false;delete(this.h["$"+key]);return true;}
Hash.prototype.keys=function(){var a=new Array();for(var i in this.h)a.push(i.substr(1));return a.iterator();}
Hash.prototype.iterator=function(){return{ref:this.h,it:this.keys(),hasNext:function(){return this.it.hasNext();},next:function(){var i=this.it.next();return this.ref["$"+i];}};}
Hash.prototype.toString=function(){var s=new StringBuf();s.b[s.b.length]="{"==null?"null":"{";var it=this.keys();while(it.hasNext()){var i=it.next();s.b[s.b.length]=i==null?"null":i;s.b[s.b.length]=" => "==null?"null":" => ";s.add(Std.string(this.get(i)));if(it.hasNext())s.b[s.b.length]=", "==null?"null":", ";}
s.b[s.b.length]="}"==null?"null":"}";return s.b.join("");}
Hash.prototype.__class__=Hash;$_={}
js.Boot.__res={}
js.Boot.__init();{Xml.Element="element";Xml.PCData="pcdata";Xml.CData="cdata";Xml.Comment="comment";Xml.DocType="doctype";Xml.Prolog="prolog";Xml.Document="document";}
{String.prototype.__class__=String;String.__name__=["String"];Array.prototype.__class__=Array;Array.__name__=["Array"];Int={__name__:["Int"]};Dynamic={__name__:["Dynamic"]};Float=Number;Float.__name__=["Float"];Bool={__ename__:["Bool"]};Class={__name__:["Class"]};Enum={};Void={__ename__:["Void"]};}
{Math.__name__=["Math"];Math.NaN=Number["NaN"];Math.NEGATIVE_INFINITY=Number["NEGATIVE_INFINITY"];Math.POSITIVE_INFINITY=Number["POSITIVE_INFINITY"];Math.isFinite=function(i){return isFinite(i);};Math.isNaN=function(i){return isNaN(i);};}
{js.Lib.document=document;js.Lib.window=window;onerror=function(msg,url,line){var f=js.Lib.onerror;if(f==null)
return false;return f(msg,[url+":"+line]);}}
js["XMLHttpRequest"]=window.XMLHttpRequest?XMLHttpRequest:window.ActiveXObject?function(){try{return new ActiveXObject("Msxml2.XMLHTTP");}catch(e){try{return new ActiveXObject("Microsoft.XMLHTTP");}catch(e1){throw"Unable to create XMLHttpRequest object.";}}}:(function($this){var $r;throw"Unable to create XMLHttpRequest object.";return $r;}(this));WebAppStyle._offSet=40;Xml.enode=new EReg("^<([a-zA-Z0-9:_-]+)","");Xml.ecdata=new EReg("^<!\\[CDATA\\[","i");Xml.edoctype=new EReg("^<!DOCTYPE ","i");Xml.eend=new EReg("^</([a-zA-Z0-9:_-]+)>","");Xml.epcdata=new EReg("^[^<]+","");Xml.ecomment=new EReg("^<!--","");Xml.eprolog=new EReg("^<\\?[^\\?]+\\?>","");Xml.eattribute=new EReg("^\\s*([a-zA-Z0-9:_-]+)\\s*=\\s*([\"'])([^\\2]*?)\\2","");Xml.eclose=new EReg("^[ \r\n\t]*(>|(/>))","");Xml.ecdata_end=new EReg("\\]\\]>","");Xml.edoctype_elt=new EReg("[\\[|\\]>]","");Xml.ecomment_end=new EReg("-->","");components.lists.AppListStyle.cellWidth=62;components.lists.AppListStyle.cellHeight=43;Constants.headerHeight=43;Constants.footerHeight=48;js.Lib.onerror=null;ApplicationStructure.PAGE1_TITLE="Silex Labs";ApplicationStructure.PAGE2_TITLE="amfPHP";ApplicationStructure.PAGE3_TITLE="Silex";ApplicationStructure.PAGE4_TITLE="Themes";ApplicationStructure.PAGE5_TITLE="Plugins";WebApp.main()