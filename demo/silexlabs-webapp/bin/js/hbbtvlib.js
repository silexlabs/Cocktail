/**
 * HbbTV library v1.0
 * 
 * (C) 2009, IRT GmbH
 * 
 * Overview:
 * 
 * 
 * function hbbtvlib_intialize()
 *   Creates and initializes HbbTV, i.e. OIPF DAE, embedded objects. 
 *   Always call this function prior to other functions of this library.
 * 
 * function hbbtvlib_show()
 *   Shows the application and requests keys via the keyset object.
 *   
 * function hbbtvlib_hide()
 *   Hides the application and releases keys via the keyset object.
 *   
 * function hbbtvlib_createApp()
 *   Create applications with the OIPF Application Manager
 *   
 * function hbbtvlib_closeApp()
 *   Destroys this application.
 * 
 * function hbbtvlib_init_broadcast()
 *   Convenience function that integrates the broadcast video in your application.
 *   
 * function hbbtvlib_release_broadcast()
 *   Convenience function that removes the broadcast video from your application.
 *
 * function hbbtvlib_current_service()
 *   Returns the DVB service ID.
 */

/**
 * The last error occured in hbbtvlib. If one of the functions returns false, 
 * the error can be retrieved via this property.
 */
var hbbtvlib_lastError = "no error";

/**
 * @return true if OIPF functions are available
 */
function hbbtvlib_initialize() {
	try {
		int_createOipfObjs();
		
		var appMgr = int_objs[int_objTypes.appMan];
		if (appMgr && typeof(appMgr.getOwnerApplication) != "undefined")
			int_app = appMgr.getOwnerApplication(document);
		else {
			hbbtvlib_lastError = "no application manager";
			int_app = null;
			return false;
		}
		return int_initKeysetObj();
	} catch (e) {
		hbbtvlib_lastError = e;
		int_app = null;
	}
	return false;
};

/**
 * This function does everything HbbTV requires an application to do
 * when it wants to get visible. 
 * 
 * @return
 */
function hbbtvlib_show() {

	try {
		int_app.show();
		if (typeof int_app.activate != "undefined") int_app.activate();
		if (typeof int_app.activateInput != "undefined") int_app.activateInput();
		int_keyset.setValue(int_ksVisible);
		return true;
	} catch (e) {
		hbbtvlib_lastError = e;
		return false;
	}
	
}

/**
 * This function does everything HbbTV requires an application to do
 * when it wants to transition to the hidden state. 
 * 
 * @return
 */
function hbbtvlib_hide() {
	try {
		if (int_bc_video) int_bc_video.style.visibility = "visible";
		int_app.hide();
		int_keyset.setValue(int_ksHidden);
		return true;
	} catch (e) {
		hbbtvlib_lastError = e;
		return false;
	}
}

/**
 * Overrides the default keysets.
 * Default is RED for hidden state, all for visible state.
 * 
 * @param visibleSet a keyset bitmask
 * @param hiddenSet a keyset bitmask
 * @return
 */
function hbbtvlib_setKeysets(visibleSet, hiddenSet) {
	if (typeof visibleSet == "Number") int_ksVisible = visibleSet;
	if (typeof hiddenSet == "Number") int_ksHidden = hiddenSet;
};


/**
 * Starts a new application and destroys this application.
 * 
 * @param dvbUrl including organization and application ids
 * @param httpUrl a fallback URL
 * 
 * @return false
 */
function hbbtvlib_createApp(dvbUrl, httpUrl) {
	if (int_app) {
		try {
			if (dvbUrl && int_app.createApplication(dvbUrl, false)) {
				int_app.destroyApplication();
				return true;
			}
			hbbtvlib_lastError = "Failed to launch dvb URL: " + dvbUrl;
		} catch (e) {
			hbbtvlib_lastError = e;
		}
		try {
			if (httpUrl && int_app.createApplication(httpUrl, false)) {
				int_app.destroyApplication();
				return true;
			}
			hbbtvlib_lastError = "Failed to launch http URL: " + httpUrl;
		} catch (e) {
			hbbtvlib_lastError = e;
		}
		return false;
	} else if (httpUrl) {
		document.location.href = httpUrl;
	}
	hbbtvlib_lastError = "OIPF application manager not available";
	return false;
};

/**
 * Destroys this application.
 * 
 * @param fallBackUrl
 * @return
 */
function hbbtvlib_closeApp(fallBackUrl) {
	if (int_app) {
		try {
			int_app.destroyApplication();
		} catch (e) {
			hbbtvlib_lastError = e;
		}
	} else if (fallBackUrl) {
		document.location.href = fallBackUrl;
	} else {
		window.close();
	}
	return false;
};

/**
 * Handle OIPF DAE Broadcast video
 */
var int_bc_video = null;
var int_bc_container = null;
var int_currentChannel = null;

/**
 * Creates and initializes a broadcast video inside the element
 * identified by the containerId. If no bc video can be included
 * the dummy picture is added instead of the bc.
 * 
 * @param parentId the id of the HTML container where the video/broadcast object will be added
 * @param objId id which shall be set for the video/broadcast object
 * @param dummyPic an optional picture to be shown if video/broadcast can not be added
 * 
 */
function hbbtvlib_init_broadcast (parentId, objId, dummyPic) {
	try {
		int_bc_container = document.getElementById(parentId);
		if (!int_bc_container) return false;

		// root container for video/broadcast object
		int_bc_container.innerHTML = '<object id="' + objId + '" type="video/broadcast" style="visibility: visible;"> </object>';
		int_bc_video = document.getElementById(objId);

		// check if OIPF video/broadcast object is supported
			try {
				if (typeof (int_bc_video.bindToCurrentChannel) != 'undefined') {
					int_bc_video.onChannelChangeSucceeded = function (channel) 
					{
						int_currentChannel = channel;
					};
					int_bc_video.onChannelChangeError = function (channel, errorState) 
					{
						int_vb_onError(objId, dummyPic);
					};
					int_bc_video.bindToCurrentChannel();
				} else if (dummyPic) {
					hbbtvlib_lastError = "video/broadcast object not supported";
					int_bc_container.innerHTML = '<img id="'+ objId + '" src="' + dummyPic + '" alt="TV Bild" />';
				}

			} catch (ex) {
				hbbtvlib_lastError = ex;
				int_vb_onError(objId, dummyPic);
			}
		
		return true;
			
	} catch (e) {
		hbbtvlib_lastError = e;
		int_vb_onError(objId, dummyPic);
	}
	return false;
};

function int_vb_onError (objId, dummyPic) {
	if (dummyPic) {
		int_bc_container.innerHTML = '<img id="'+ objId + '" src="' + dummyPic + '" alt="TV Bild" />';
	} else 
	{
		int_bc_container.innerHTML = "";
	}
	int_currentChannel = null;
	int_bc_video = null;
}

/**
 * Releases the video/broadcast object and removes the object from the DOM.
 */
function hbbtvlib_release_broadcast () {
	try {
		if (int_bc_video && typeof (int_bc_video.release) != "undefined") {
			int_bc_video.release();
			int_bc_video = null;
		}
		if (int_bc_container) {
			int_bc_container.innerHTML = "";
			int_bc_container = null;
		}
		int_currentChannel = null;
	} catch (e) {
		hbbtvlib_lastError = e;
	}
};

/**
 * Requires hbbtvlib_init_broadcast
 * 
 * @return the DVB service id of the current presented service or -1
 */
function hbbtvlib_current_service () {
	try {
		return int_bc_video.currentChannel.sid;
	} catch (e) {
		hbbtvlib_lastError = e;
	}
	return -1;
};

/**
 * Tunes to a DVB service identified by the DVB Triplet. The application may
 * get killed due to the application life cycle, i.e. if it is not signalled
 * with their application ID on the tuned service.
 * 
 * @param onid the original network id
 * @param tsid the transport stream id
 * @param sid the service id
 * 
 * @return false if there is no video broadcast object available or there is no
 * 	channel found for this triplet
 */
function hbbtvlib_tuneTo(onid, tsid, sid) {
	try {
		var chLst = int_bc_video.getChannelConfig().channelList;
		
		onid = (typeof(onid) == 'number') ? onid : parseInt(onid, 10);
		tsid = (typeof(tsid) == 'number') ? tsid : parseInt(tsid, 10);
		sid = (typeof(sid) == 'number') ? sid : parseInt(sid, 10);
		
		var ch = chLst.getChannelByTriplet(onid, tsid, sid);
		
		if (ch == null) {
			hbbtvlib_lastError = "Tuning failed, no channel object found for given DVB triplet.";
			return false;
		}
		
		int_bc_video.setChannel(ch, false);
		
		return true;
	}catch (e) {
		hbbtvlib_lastError = "Tuning failed due to " + e;
	}
	return false;
};

/*
 * Library internal (private) properties and functions.
 */

/**
 * Array of OIPF DAE embedded objects. Access Key is the mime-type without "application/".
 */
var int_objs = new Array();

var int_objTypes = {
	appMan: "oipfApplicationManager",
	config: "oipfConfiguration"
};

/**
 * OIPF DAE Application object
 * 	- to show/hide the application
 * 	- create or destroy applications
 *  - providing the keyset object
 */
var int_app = null;

/**
 * The OIPF keyset object used to request keys from terminal.
 * 
 * Usually this is the RED button in hidden mode, and up to all
 * available keys in visible mode.
 */
var int_keyset = null;

var int_ksHidden = null;

var int_ksVisible = null;

/**
 * Internal function to create OIPF embedded objects,
 * like ApplicationManager etc., if not already existing.
 */
function int_createOipfObjs() {
	if (int_objs.length) return;
	// Look for existing objects
	var objects = document.getElementsByTagName("object");
	for (var i=0; i<objects.length; i++) {
		var sType = objects.item(i).getAttribute("type");
		for (var eType in int_objTypes) {
			if (sType == "application/" + int_objTypes[eType]) {
				int_objs[int_objTypes[eType]] = objects.item(i);
			}
		}
	}
};

/**
 * Retrieves the keyset object for HbbTV 1.1.1 and 0.5 implementations.
 * 
 * Sets default keysets for hidden and visible modes.
 */
function int_initKeysetObj () {
	// try HbbTV 1.1.1
	try {
		int_keyset = int_app.privateData.keyset;
		hbbtvlib_lastError = "privateData";
	} catch (e) {
		int_keyset = null;
		// try HbbTV 0.5
		try {
			var tmp = int_objs[int_objTypes.config].keyset;
			tmp.setValue = function (val) {this.value = val;};
			int_keyset = tmp;
			hbbtvlib_lastError = "oipfConfig";
			
		} catch (e) {
			int_keyset = null;
		}
	}

	if (int_keyset) {
		// set default key sets
		if (!int_ksHidden)  int_ksHidden  = int_keyset.RED;
		if (!int_ksVisible) int_ksVisible =  0x33F; // color + nav + vcr + numeric + alpha
	}

	return int_keyset != null;
};