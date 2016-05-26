package org.cocos2dx.lib;

public class Cocos2dxLayerManager {
	
	// strName,作为该图层的唯一标示
	public static void addLayer(String strName){
		nativeAddLayer( strName );
	}
	
	public static void delLayer(String strName){
		
	}
	
	
	 private static native void nativeAddLayer(String strName);
	 private static native void nativeDelLayer(String strName);
}
