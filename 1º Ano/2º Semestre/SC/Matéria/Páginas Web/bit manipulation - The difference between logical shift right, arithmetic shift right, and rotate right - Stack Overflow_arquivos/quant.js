/* Copyright (c) 2008-2020, Quantcast Corp. */
!function(window){function RequireDependencyError(n){Error.apply(this),this.name="RequireDependencyError",this.message=n||""}RequireDependencyError.prototype=Error.prototype;var amd={},definitions={};amd.require=function(n,e){"function"==typeof n&&(e=n,n=[]);for(var t=[],r=0;r<n.length;r++){var o=n[r];if(!definitions.hasOwnProperty(o))throw new RequireDependencyError("No module named "+o+" has been defined");t[r]=definitions[o]}return e.apply({},t)};var array=Array.prototype,available=function(n,e){return"function"==typeof n[e]},map="map",forEach="forEach",reduce="reduce",indexOf="indexOf";with(available(array,map)||(array[map]=function(n,e){var t=[];e||(e=this);for(var r=0;r<this.length;r++)t[r]=n.call(e,this[r],r,this);return t}),available(array,forEach)||(array[forEach]=array[map]),available(array,reduce)||(array[reduce]=function(n,e){var t=0;for(void 0===e&&(e=this[t++]);t<this.length;t++)e=n.call(this,e,this[t],t,this);return e}),available(array,indexOf)||(array[indexOf]=function(n){for(var e=0;e<this.length;e++)if(this[e]==n)return e;return-1}),amd.define=function(n,e,t){definitions.hasOwnProperty(n)||(definitions[n]=amd.require(e,t))},amd)define("quant/origin",[],function(){return function(n){for(var e=n.domain||"",t=new Date(0).toUTCString(),r=e.split("."),o=1;o<=r.length;o++){var i=r.slice(-o).join("."),a="_dlt=1; domain="+i;if(n.cookie=a,/_dlt=1/.test(n.cookie))return n.cookie=a+"; expires="+t,i}return e}}),define("quant/windows",[],function(){return function(n,e){if(void 0===n)throw new Error("window many not be undefined");if(void 0===e)throw new Error("top may not be undefined");e=e.self,this.depth=0;var t=n.self;for(this.top=t;t!==e;){t=t.parent.self;try{t.location.href&&(this.url=t.location.href,this.top=t)}catch(n){}this.depth++}this.locate=function(t){for(var r=n;;){try{if(t in r.frames)return r}catch(n){}if(r===e)break;r=r.parent.self}}}}),define("quant/log",[],function(){function n(n,e){this.isDebug=/qcdbgc=1$/.test(window.location.toString());var t=function(){return(new Date).toString()},r=function(r,o){"undefined"!=typeof console&&console.log(r+" "+t()+" "+o),e&&"ERROR"==r&&n.beacon("//"+e+"/log/"+r.toLowerCase()+"?msg="+encodeURI(o))};this.error=function(n,e){void 0!==e&&void 0!==e.stack&&(n+=" caused by "+e.message+" at:\n"+e.stack),r("ERROR",n)},this.debug=function(n){this.isDebug&&r("DEBUG",n)}}return n}),define("quant/ready",[],function(){function n(){var n=!1,e=[];document.readyState in{complete:!0,interactive:!0}&&(n=!0);var t=function(){for(n=!0;e.length>0;)e.shift()()};document.addEventListener?(document.addEventListener("DOMContentLoaded",t,!1),window.addEventListener("load",t,!1)):document.attachEvent&&(document.attachEvent("onreadystatechange",t,!1),window.attachEvent("onload",t)),this.ready=function(t){n?t():e.push(t)}}return(new n).ready}),define("quant/promise",[],function(){function n(u){var c,s,f=[],l=e,d=function(n){return n},p=function(n,e,t,r){try{var i=n(r);o(i)?(i.then(e),i.catch(t)):e(i)}catch(n){t(n)}},h=function(n){c=n,l=t,f.forEach(function(e){e.push(n),p.apply(0,e)})},v=function(n){s=n,l=r,f.forEach(function(e){e[r](n)})},g=function(n,e,t){return function(r){p(n,e,t,r)}};try{u(h,v)}catch(n){v(n)}return{then:function(o){switch(l){case e:return new n(function(n,e){f.push([o,n,e])});case t:return i(o(c));case r:return a(s)}},catch:function(o){switch(l){case e:return new n(function(n,e){f.push([d,n,g(o,n,e)])});case t:return i(c);case r:return i(o(s))}}}}var e=0,t=1,r=2,o=function(n){return"object"==typeof n&&"then"in n&&"function"==typeof n.then},i=function(n){return o(n)?n:{then:function(e){return i(e(n))},catch:function(n){return this}}},a=function(n){return{then:function(n){return this},catch:function(e){return i(e(n))}}};return n.resolve=i,n.reject=a,n.all=function(n){return n.length?n.map(function(n){return n.then(function(n){return[n]})}).reduce(function(n,e){return n.then(function(n){return e.then(function(e){return n.concat(e)})})}):i([])},n}),define("quant/loader",["quant/ready","quant/promise"],function(n,e){function t(t,r){var o,i=[];n(function(){o=r.getElementsByTagName("head")[0]});var a=function(n){var e=new Image;return e.src=n,e};this.image=function(n){return new e(function(e,t){var r=a(n);i.push(r),r.onload=function(){e(r),i.shift(),delete r.onload,delete r.onerror},r.onerror=t})},this.beacon=function(n){var e=t.navigator;e&&e.sendBeacon?e.sendBeacon(n):a(n)};var u=function(n,e,t){var o=r.createElement("script");o.type="text/javascript",o.src=n;var i=function(){e(o),o.onreadystatechange=null,o.onload=null,o.onerror=null};return o.onload=i,o.onreadystatechange=function(){o.readyState in{loaded:1,complete:1}&&i()},o.onerror=t,o};this.script=function(t){return new e(function(e,r){n(function(){var n=u(t,e,r);o.firstChild?o.insertBefore(n,o.firstChild):o.appendChild(n)})})}}return t}),define("quant/json",[],function(){var localJSON=window.JSON||{};return void 0!==localJSON.stringify&&'{"test":["1"]}'===localJSON.stringify({test:["1"]})||(localJSON.stringify=function(n){var e=typeof n;if("object"!==e||null===n)return"string"===e&&(n='"'+n+'"'),String(n);var t,r,o=[],i=n&&n.constructor===Array;for(t in n)r=n[t],"function"!==(e=typeof r)&&("string"===e?r='"'+r+'"':"object"===e&&null!==r&&(r=localJSON.stringify(r)),o.push((i?"":'"'+t+'":')+String(r)));return(i?"[":"{")+String(o)+(i?"]":"}")},localJSON.parse=localJSON.parse||function(string){return eval("("+string+")")}),localJSON}),define("quant/event",[],function(){function n(){this.add=function(n,e,t){n.addEventListener?n.addEventListener(e,t):"function"==typeof jQuery?jQuery(n).on(e,t):n.attachEvent&&n.attachEvent("on"+e,t)},this.remove=function(n,e,t){n.removeEventListener?n.removeEventListener(e,t):"function"==typeof jQuery?jQuery(n).off(e,t):n.detachEvent&&n.detachEvent("on"+e,t)},this.trigger=function(n,e,t){var r=n.ownerDocument;if(n.dispatchEvent&&r.createEvent){var o=r.createEvent("Event");if(o.initEvent(e,!0,!0),void 0!==t)for(var i in t)i in o||(o[i]=t[i]);n.dispatchEvent(o)}else"function"==typeof jQuery&&jQuery(n).trigger(e,t)}}return new n}),define("quant/now",[],function(){return function(){return(new Date).getTime()}}),define("quant/consent/truste",["quant/json","quant/promise","quant/event","quant/now"],function(n,e,t,r){return function(o,i,a,u,c,s,f,l){var d,p={},h=function(n){var e=n.source[0];return"p"+n.consent[0]+("a"==e?"e":"i")};"object"==typeof u&&"function"==typeof u.callApi?(!0,d=function(n,t,r,o){var i=u.callApi(t,o,l,c,r);return n.cm=h(i),e.resolve(!0)}):d=function(u,s,f,d){return o.depth>0&&(t.add(i,"message",function(e){var t=e.data;if("string"==typeof t&&t.indexOf("PrivacyManagerAPI")>0)try{t=n.parse(t)}catch(n){return}else if(void 0!==t.PrivacyManagerAPI){var r=t.PrivacyManagerAPI;u.cm=h(r)}}),a.postMessage(n.stringify({PrivacyManagerAPI:{timestamp:r(),action:s,self:d,domain:l,authority:c,type:f}}),"*")),e.resolve(!0)},this.consent=function(n){return d(n,"getConsent",s,f)},this.parameters=p}}),define("quant/consent/uspapi",["quant/promise","quant/json","quant/event","quant/now"],function(n,e,t,r){return function(o,i,a,u){var c;if("function"==typeof i.__uspapi)c=function(e,t){return new n(function(n,e){i.__uspapi("getUSPData",t,function(t,r){r&&void 0!==t?n(t.uspString):e(t)})}).catch(function(n){return a.error("[USPAPI] unsuccessful: "+n),!0})};else{var s=(o.locate(u),{});t.add(i,"message",function(n){var t=n.data;if("string"==typeof t&&"{"==t[0])try{t=e.parse(t)}catch(n){return}if(t.hasOwnProperty("__uspapiReturn")){var r=t.__uspapiReturn,o=r.callId,i=s[o];if(void 0===i)return;r.success?i[0](r.returnValue):i[1](r.returnValue)}}),c=function(e,t){var i=o.locate(u);if(void 0===i)return n.resolve(void 0);var a=r();return new n(function(n,r){s[a]=[n,r],i.postMessage({__uspapiCall:{command:e,version:t,callId:a}})})}}this.consent=function(n){return c("getUSPData",1).then(function(e){return e&&"string"==typeof e.uspString&&(n.us_privacy=e.uspString),!0})}}}),define("quant/consent/tcf1.1",["quant/promise","quant/json","quant/event","quant/now"],function(n,e,t,r){return function(o,i,a,u){var c,s;if("function"==typeof i.__cmp)s=function(e,t){return new n(function(n,r){i.__cmp(e,t,function(e,t){t?n(e):r(e)})})};else{var f={};t.add(i,"message",function(n){var t=n.data;if(void 0===t)return void a.error("[TCF]: Recieved undefined message");if("string"==typeof t&&"{"==t[0])try{t=e.parse(t)}catch(n){return}if(t.hasOwnProperty("__cmpReturn")){var r=t.__cmpReturn,o=r.callId,i=f[o];if(void 0===i)return;r.success?i[0](r.returnValue):i[1](r.returnValue)}}),s=function(t,i){var a=o.locate(u);if(void 0===a)return n.resolve({gdprApplies:!1});var c=r();return new n(function(n,r){f[c]=[n,r],a.postMessage(e.stringify({__cmpCall:{command:t,parameter:i,callId:c}}),"*")})}}this.consent=function(n){return void 0===c&&(c=s("getVendorConsents",[11]).then(function(e){return e.gdprApplies&&"false"!=e.gdprApplies?(n.gdpr=1,s("getConsentData",null).then(function(t){n.gdpr_consent=t.consentData;var r=e.purposeConsents||e.purposes,o=!0;return"object"==typeof r&&(o=r[1]),o&&(o=!e.vendorConsents||e.vendorConsents[11]),o})):(n.gdpr=n.gdpr||0,!0)}).catch(function(e){return a.error(e),n.gdpr=n.gdpr||0,!0})),c}}}),define("quant/consent-manager",["quant/promise","quant/json"],function(n,e){return function(e){var t,r={},o=function(o){return void 0===t&&(t=n.all(e.map(function(n){return n.consent(r)})).then(function(n){return n.reduce(function(n,e){return n&&e},!0)})),t.then(function(n){if(n)return o()})};this.consent=o,this.wrap=function(n){return function(){var e=this,t=arguments;return o(function(){return n.apply(e,t)})}},this.parameters=r}}),define("quant/consent/tcf2.0",["quant/promise","quant/json","quant/event","quant/now"],function(n,e,t,r){function o(n,e){var t=e.gdprApplies,r=e.purpose,o=e.vendor,i=o&&o.consents&&o.consents[s],a=o&&o.legitimateInterests&&o.legitimateInterests[s],u=e.publisher?e.publisher.restrictions:{};return!t||n.map(function(n){var e=!!r.consents&&r.consents[n],t=!!r.legitimateInterests&&r.legitimateInterests[n],o=u&&u[n]?u[n][s]:null;return 0!==o&&(!(!i||!e||2===o||-1==l.indexOf(n)&&1!==o)||!(1===o||!a||!t||-1!=d.indexOf(n)||-1!=l.indexOf(n)&&2!==o))}).reduce(function(n,e){return n&&e},!0)}function i(i,s,l,d){var q,m;if("function"==typeof s.__tcfapi)m=function(e,t){return new n(function(n,r){s.__tcfapi(e,p,function(t,o){if(o){var i=t.eventStatus;e===h&&t.gdprApplies&&"useractioncomplete"!==i&&"tcloaded"!==i||n(t)}else r(t)},t)})};else{var y={},w={};t.add(s,"message",function(n){var t=n.data;if(void 0===t)return void l.error(a+"Recieved undefined message");if("string"==typeof t&&"{"==t[0])try{t=e.parse(t)}catch(n){return}if(t.hasOwnProperty(v)){var r=t[v],o=r.callId,i=y[o];if(void 0===i)return;var s=r.returnValue;r.success?w[o]===h&&s.gdprApplies&&"useractioncomplete"!==s.eventStatus&&"tcloaded"!==s.eventStatus||i[u](s):i[c](s)}}),m=function(t,o){var a=i.locate(d);if(void 0===a)return n.resolve({gdprApplies:!1});var u=r();return new n(function(n,r){y[u]=[n,r],w[u]=t;var i={};i[g]={command:t,parameter:o,version:p,callId:u},a.postMessage(e.stringify(i),"*")})}}this.consent=function(n){return void 0===q&&(q=m(h).then(function(e){return e.gdprApplies&&"false"!=e.gdprApplies?(n.gdpr=1,n.gdpr_consent=e.tcString):n.gdpr=n.gdpr||0,o(f,e)}).catch(function(e){return l.error(e),n.gdpr=n.gdpr||0,!0})),q}}var a="[TCF2]: ",u=0,c=1,s=11,f=["1","3","7","8","9","10"],l=["1","3"],d=["1","3"],p=2,h="addEventListener",v="__tcfapiReturn",g="__tcfapiCall";return i.resolveConsent=o,i}),define("quant/qtrack",[],function(){function n(n,e){for(var t in e)e.hasOwnProperty(t)&&(n[t]=e[t])}function e(e,t,i){for(var a=0;a<r.length;a++){var u={qacct:r[a],labels:i?e:"_fp.event."+e,event:"refresh"};if(n(u,o),void 0!==t&&null!==t)for(var c in t)t.hasOwnProperty(c)&&("product_id"===c&&t[c].constructor===Array&&(t[c]=t[c].join(",")),u[s[c]||c]=t[c]);window._qevents.push(u)}}function t(t,s,f){if(t===a){if(-1!==r.indexOf(s))return;r.push(s);var l={qacct:s};n(o,f),n(l,o),window._qevents.push(l)}else t===u?-1!==i.indexOf(s)?e(s,f,!1):console.warn("Unsupported event by track, please use "+c+" for this event."):t===c&&e(s,f,!0)}var r,o,i=["PageView","ViewContent","Search","AddToWishlist","AddToCart","InitiateCheckout","AddPaymentInfo","Purchase","Lead","Register","StartTrial","Subscribe","SubmitApplication"],a="init",u="track",c="trackCustom",s={order_id:"orderid",value:"revenue"};return function(){if(window.qtrack||(window.qtrack=function(){window.qtrack.impl.apply(window.qtrack,arguments)}),!window.qtrack.impl&&(r=[],o={},window.qtrack.impl=t,window.qtrack&&window.qtrack.q))for(;window.qtrack.q.length>0;)t.apply(t,window.qtrack.q.shift())}}),define("quant/hashing",[],function(){function n(){this.FNV=function(e){var t,r,o,i;return t=2166136261,r=3386659096,o=n(t,e),i=n(r,e),Math.round(Math.abs(o*i)/65536).toString(16)};var n=function(n,e){var t;for(t=0;t<e.length;t++)n^=e.charCodeAt(t),n+=(n<<1)+(n<<4)+(n<<7)+(n<<8)+(n<<24);return n}}return new n}),define("quant/normalize",["quant/hashing"],function(n){return function(e,t,r,o,i,a){var u,c={},s=null,f=/^[^\s@]+@[^\s@]+\.[^\s@]+$/,l=/^[A-Fa-f0-9]{64}$/,d=2,p={};for(u in t)p[u]=void 0!==t[u],t.hasOwnProperty(u)&&"string"==typeof t[u]&&("uid"!==u&&"uh"!==u?"qacct"!==u&&(t[u].length>0?c[u+e]=encodeURIComponent(t[u]):p[u]=!1):(a||(t[u].match(l)&&(d=1),t[u].match(f)&&(d=0),s=n.FNV(t[u])),delete t[u]));for(u in r)r.hasOwnProperty(u)&&"string"==typeof r[u]&&!p[u]&&(c[u+e]=encodeURIComponent(r[u]));return c["rf"+e]=""+i,"string"==typeof s&&(t.uh=s,c["uh"+e]=encodeURIComponent(s)),c["uht"+e]=""+d,c["a"+e]=o,c}}),define("quant.js",["quant/origin","quant/windows","quant/log","quant/loader","quant/consent/truste","quant/consent/uspapi","quant/consent/tcf1.1","quant/consent-manager","quant/consent/tcf2.0","quant/qtrack","quant/normalize","quant/hashing"],function(n,e,t,r,o,i,a,u,c,s,f,l){return void 0===window.__qc&&(window.__qc=function(s,d,p){if(s.__qc)return s.__qc;var h,v,g,q,m,y,w,_,b,E,O,S,j,P,C,k,I,x,R,A,D,N,T,M,z,U,L,V,J,F,B,Q,G,$,W,Z,H,K,X,Y,nn,en,tn,rn,on,an,un,cn,sn=n(d),fn=new e(s,s.top),ln=new r(s,d),dn=new t(ln,"quantcount.com"),pn=new u([new o(fn,s,s.top,s.PrivacyManagerAPI,"truste.com","advertising","quantserve.com",sn),new i(fn,s,dn,"__uspapiLocator"),new a(fn,s,dn,"__cmpLocator"),new c(fn,s,dn,"__tcfapiLocator")]),hn=["a","ce","cm","dst","enc","fpa","fpan","je","ns","ogl","rf","tzo","sr"],vn=["4dcfa7079941","127fdf7967f31","588ab9292a3f","32f92b0727e5","22f9aa38dfd3","a4abfe8f3e04","18b66bc1325c","958e70ea2f28","bdbf0cb4bbb","65118a0d557","40a1d9db1864","18ae3d985046","3b26460f55d"],gn=!1,qn=!1,mn=0,yn=[],wn=[],_n=[],bn=[],En={},On=0,Sn=null,jn={},Pn={},Cn=null,kn=[].slice;!function(){var n;n=d.createElement("script"),h="async"in n?1:n.readyState?2:3,n=null}();var In=function(n){try{return{init:E,hash:l.FNV,push:O,rules:$,require:require,hasRules:Z,defaults:Y,__qc:function(){return!0}}[n].apply(null,kn.call(arguments,1))}catch(n){return dn.error(n),!1}};return In.evts=0,In.v=2,In.SD=vn,In.qpixelsent=[],G=function(n){var e,t=n?n.length||0:0;for(e=0;e<t;e++)if(!n[e])return!1;return!0},X=function(n){(n=n||s._qacct)&&(z(bn,n)||bn.push(n))},z=function(n,e){var t,r=n.length;for(t=0;t<r;t++)if(n[t]===e)return!0;return!1},V=function(n){return{}.toString.call(n).match(/\s([a-zA-Z]+)/)[1].toLowerCase()},J=function(n){var e,t,r;if("array"===(t=V(n)))return n.slice(0);if("object"===t){e={};for(r in n)n.hasOwnProperty(r)&&(e[r]=n[r]);return e}return"string"===t?""+n:n},O=function(n,e){C(n,e)},Z=function(n){return z(_n,n)},Y=function(n,e){var t;n&&(t=jn[n],t&&(e=T(e,t)),e.qacct&&delete e.qacct,jn[n]=e)},nn=function(n){var e,t,r,o,i,a;if(m(n)){i=n;for(o in i){if("string"==typeof i[o]){e=n.event||"load",t=n.media||"webpage","rule"!==e&&"load"!==e||"webpage"!==t&&"ad"!==t?C(n):(a=n.qacct||s._qacct,n.qacct=a,r=Pn[a],r=r?T(r,n):n,Pn[a]=r),X(n.qacct);break}"object"==typeof i[o]&&null!=i[o]&&nn(i[o])}}},T=function(n,e){var t={};return t.qacct=n.qacct||e.qacct,"load"===n.event||"load"===e.event?t.event="load":n.event&&e.event?t.event=n.event||e.event:t.event=null,t.media=null,"webpage"===n.media||"webpage"===e.media?t.media="webpage":"ad"===n.media||"ad"===e.media?t.media="ad":t.media=n.media||e.media,M(t,n,e),M(t,e,n),t.event||delete t.event,t.media||delete t.media,t},M=function(n,e,t){var r,o,i,a,u,c;for(r in e)e.hasOwnProperty(r)&&!n.hasOwnProperty(r)&&(o=e[r],i=t[r],a="",u=!!o&&"string"==typeof o,c=!!i&&"string"==typeof i,u&&(a=o),u&&c&&(a+=","),c&&(a+=i),n[r]=a)},en=function(){var n,e,t=[];if(!(On>0)){L();for(n in Pn)Pn.hasOwnProperty(n)&&Pn[n]&&(e=Pn[n],t.push(e),delete Pn[n]);1==t.length&&C(t[0]),t.length>1&&C(t)}},tn=function(){var n,e,t,r=[];for(t=bn.slice(0),n=0;n<t.length;n++)e=t[n],Z(e)||r.push(e);if(0===r.length)en();else for(n=0;n<r.length;n++)e=r[n],_n.push(e),D(e)},N=function(n,e,t,r){var o;n=s.location.protocol+"//"+n,Sn=d.scripts&&d.scripts[0]||null;var i=Sn&&Sn.parentNode||d.head||d;if(o=d.createElement("script"),1===h)o.src=n,o.async=!0,o.onload=e,t&&(o.onerror=function(n){o.onerror=null,t(n)}),i.insertBefore(o,Sn);else if(2===h){var a=!1;o.onload=o.onreadystatechange=function(){a||"loaded"!=o.readyState&&"complete"!=o.readyState||(a=!0,o.onreadystatechange=null,e())},o.src=n,i.insertBefore(o,Sn)}else r&&r()},D=function(n){On++,N("rules.quantcount.com/rules-"+n+".js",function(){En[n]=2===h?2:0,rn()},function(e){En[n]=1,rn()},function(){En[n]=4,rn()})},rn=function(){On-=On>0?1:0,en()},$=function(){var n,e,t,r=!0;if(arguments.length){for(t=function(n){r?nn(n):C(n,!0)},n=0;n<arguments.length;n++)e=kn.call(arguments[n],0),e.splice(1,0,t),W.apply(null,e);r=!1,gn&&en()}},W=function(n,e){var t,r,o,i,a,u,c,s=[],f=[],l=e||C;if((r=kn.call(arguments,2))&&r.length){for(o=r[0]||G,i=r[1],a=r[2],t=a.length,u=0;u<t;u++)s.push(!1),f.push(null);c={p:n,f:s,r:o,c:a,a:i,v:f},Z(n)||_n.push(n),wn.push(c),H(c,l)}else _n.push(n),En[n]=6},H=function(n,e){var t,r=n&&n.c?n.c.length:0;for(t=0;t<r;t++)!function(t){var r,o;try{r=n.c[t][0],o=n.c[t].slice(1),o.splice(0,0,function(r){n.f[t]=!0,n.v[t]=r,K(n,e)}),r.apply(null,o)}catch(r){n.f[t]=!0,n.v[t]=!1,K(n,e)}}(t)},K=function(n,e){var t,r,o,i,a,u,c,s=n.a,f=n.f,l=n.v,d=n.r||G;if(t=G(f),t&&(t=t&&d(l)),t)for(a=0;a<s.length;a++)try{r=s[a][0],o=s[a].length>1?s[a].slice(1):[],o=o.concat(n.v),i=r.apply(null,o),u={qacct:n.p,event:"rule"};for(c in i)i.hasOwnProperty(c)&&"qacct"!==c&&(u[c]=i[c]);e(u)}catch(n){continue}},v=function(){return g(0)!==g(6)?1:0},g=function(n){var e=new Date(2e3,n,1,0,0,0,0),t=e.toGMTString();return e-new Date(t.substring(0,t.lastIndexOf(" ")-1))},q=function(n){return n.replace(/\./g,"%2E").replace(/,/g,"%2C")},m=function(n){return void 0!==n&&null!=n},y=function(){return Math.round(2147483647*Math.random())},w=function(n){var e,t,r,o="",i=d.cookie;return i?(e=i.indexOf(n+"="),t=e+n.length+1,e>-1&&(r=i.indexOf(";",t),r<0&&(r=i.length),o=i.substring(t,r)),o):o},P=function(n){return"P0-"+y()+"-"+n.getTime()},j=function(n,e,t){return["__qca=",n,"; expires=",e.toGMTString(),"; path=/; domain=",t].join("")},S=function(){var n,e,t,r,o,i,a=["","",""];if(1===mn)return a[0]=";fpan=u;fpa=",a;for(n=l.FNV(sn),i=0;i<vn.length;i++)if(vn[i]===n)return a[0]=";fpan=u;fpa=",a;return e=new Date,t=w("__qca"),t.length>0||Cn?(0===t.length&&(t=Cn,a[1]=j(Cn,new Date(e.getTime()+338688e5),sn)),a[0]=";fpan=0;fpa="+t):(Cn=P(e),a[1]=j(Cn,new Date(e.getTime()+338688e5),sn),a[0]=";fpan=1;fpa="+Cn),r=w("_pubcid"),o=w("_pubcid_optout"),(0===o.length||0===o)&&r.length>0?a[2]=";pbcn=1;pbc="+r:a[2]=";pbcn=u;pbc=",a},_=function(){var n=S()[1];n&&(d.cookie=n)},b=function(n){d.cookie=n+"=; expires=Thu, 01 Jan 1970 00:00:01 GMT; path=/; domain="+sn},B=function(n){var e,t;if(n&&"object"===V(n))for(t=0;t<hn.length;t++)e=hn[t],n.hasOwnProperty(e)&&n[e]&&delete n[e]},R=function(n,e,t){var r,o,i;return e&&"string"==typeof e.qacct?r=e.qacct:"string"==typeof s._qacct&&(r=s._qacct),r&&0!==r.length?(e=F(r,e),delete Pn[r],i=jn[r],o=En[r],m(o)||(o=3),cn(e,i,t,r)?null:f(n,e,i,r,o,Q())):null},x=function(n){var e,t=[],r=[],o=[];for(e in n)n[e]&&n.hasOwnProperty(e)&&("uh"===e||"uht"===e?r.push(";"+e+"="+n[e]):t.push(e+"="+n[e]));return o.push(t.join(";")),o.push(r.join("")),o},A=function(){var n,e,t,r,o,i=d.getElementsByTagName("meta"),a="";for(n=0;n<i.length;n++){if(o=i[n],a.length>=1e3)return encodeURIComponent(a);m(o)&&m(o.attributes)&&m(o.attributes.property)&&m(o.attributes.property.value)&&m(o.content)&&(e=o.attributes.property.value,t=o.content,e.length>3&&"og:"===e.substring(0,3)&&(a.length>0&&(a+=","),r=t.length>80?80:t.length,a+=q(e.substring(3,e.length))+"."+q(t.substring(0,r))))}return encodeURIComponent(a)},Q=function(){var n,e=!1;return m(s.external)&&(n=s.external,e="function"==typeof n.InPrivateFilteringEnabled&&!0===n.InPrivateFilteringEnabled()),e||"1"==p.doNotTrack||"yes"===p.doNotTrack||"1"==p.msDoNotTrack},C=function(n,e){var t,r,o,i,a,u,c,f,l,h,g=y(),q="",w="",_="",b="",E="",O="u",j="1",P=[];if(mn=0,m(In.qpixelsent)||(In.qpixelsent=[]),m(n)){if("object"===(l=V(n)))o=R("",n,e);else if("array"===l)for(a=0;a<n.length;a++)h=R("."+(a+1),n[a],e),o=0===a?h:T(o,h)}else"string"==typeof _qacct&&(o=R("",null,e));o&&(t=p.cookieEnabled?"1":"0",void 0!==p.javaEnabled&&(O=p.javaEnabled()?"1":"0"),m(s._qmeta)&&(w=";m="+encodeURIComponent(s._qmeta),s._qmeta=null),self.screen&&(q=screen.width+"x"+screen.height+"x"+screen.colorDepth),u=new Date,c=v(),f=S()[0],pubcidCookie=S()[2],s.location&&s.location.href&&(_=encodeURIComponent(s.location.href)),d&&d.referrer&&(E=encodeURIComponent(d.referrer)),s.self===s.top&&(j="0"),o.url?b=_:o.url=_,o.ref||(o.ref=E||""),r=A(),i=x(o),P.push("/pixel;r="+g+";"+i[0]),P.push(i[1]),P.push(f+pubcidCookie),P.push(";ns="+j+";ce="+t+";qjs=1;qv=82efd7d8-20210517233434"),P.push((o.ref?"":";ref=")+";d="+sn+";je="+O+";sr="+q+";dst="+c+";et="+u.getTime()+";tzo="+u.getTimezoneOffset()+(b?";ourl="+b:"")+w+";ogl="+r),yn.push(P),I())},k=function(n){pn.consent(function(){return!0}).then(function(n){return n||b("__qca"),n?"quantserve.com":"quantcount.com"}).then(function(e){var t=pn.parameters,r=function(){return function(){return"quantserve.com"===e?[n[1],n[2]].join(""):";uh=u;uht=u"}}();return ln.image(["//pixel.",e,n[0],r(),n[3],";cm=",t.cm,1===t.gdpr?";gdpr=1;gdpr_consent="+t.gdpr_consent:";gdpr=0",t.us_privacy?";us_privacy="+t.us_privacy:"",n[4]].join("")).then(function(n){n&&"number"==typeof n.width&&3===n.width?b("__qca"):"quantserve.com"===e&&_()})})},I=function(){for(;yn.length;)k(yn.shift())},on=function(){var n,e,t=arguments;for(U([].slice.call(t)),e=0;e<t.length;e++)n=t[e],C(n);bn.length?tn():en()},U=function(n){var e,t=V(n);if("array"===t)for(e=0;e<n.length;e++)U(n[e]);else"object"===t&&X(n.qacct||s._qacct)},L=function(){var n;if(qn||s._qevents.length||s.ezt.length||"undefined"==typeof _qacct||(C({qacct:s._qacct}),qn=!0),!In.evts){for(n in s._qevents)s._qevents[n]!==s._qevents.push&&s._qevents.hasOwnProperty(n)&&C(s._qevents[n]);for(n in s.ezt)s.ezt[n]!==s.ezt.push&&s.ezt.hasOwnProperty(n)&&C(s.ezt[n]);s._qevents={push:on},s.ezt.push=function(){var n,e=arguments;if(m(s.queueManager))for(n=0;n<e.length;n++)s.queueManager.push(e[n]);else on.apply(this,arguments)},In.evts=1}},un=function(n){var e;n&&(e=J(n),U(n),s._qevents.push(e),n=null)},an=function(n){n.push=function(){return U([].slice.call(arguments)),tn(),[].push.apply(n,arguments)}},cn=function(n,e,t,r){e=e||{};var o=(n?n.media:e.media)||"webpage",i=(n?n.event:e.event)||"load";if("ad"===o&&(mn=1),"webpage"===o&&"load"===i){for(var a=0;a<In.qpixelsent.length;a++)if(In.qpixelsent[a]===r&&!t)return!0;In.qpixelsent.push(r)}return!1},F=function(n,e){var t=Pn[n];return e?t&&(e=T(e,t)):e=t,B(e),e},E=function(){m(s._qevents)||(s._qevents=[]),m(s.ezt)||(s.ezt=[]),un(s._qoptions),un(s.qcdata),un(s.smarttagdata),In.evts||(an(s._qevents),an(s.ezt)),U(s.ezt),U(s._qevents),U({qacct:s._qacct}),s._qoptions=null,bn.length?tn():en(),gn=!0},s.quantserve=s.quantserve||E,In.quantserve=E,In}(window,window.document,window.navigator)),window.quantserve(),s(),window.__qc})}(window);