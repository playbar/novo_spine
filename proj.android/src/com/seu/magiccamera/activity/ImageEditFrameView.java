package com.seu.magiccamera.activity;

import com.seu.magicfilter.camera.MagicImageDisplay;

import android.content.Context;
import android.content.DialogInterface;

public class ImageEditFrameView extends ImageEditFragment{

	public ImageEditFrameView(Context context, MagicImageDisplay magicDisplay) {
		super(context, magicDisplay);

	}

	@Override
	protected boolean isChanged() {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	protected void onDialogButtonClick(DialogInterface dialog) {
		// TODO Auto-generated method stub
		
	}
}
