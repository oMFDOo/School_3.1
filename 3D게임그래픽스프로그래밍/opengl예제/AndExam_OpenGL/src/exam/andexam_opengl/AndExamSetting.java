package exam.andexam_opengl;

import android.app.*;
import android.content.*;
import android.os.*;
import android.view.*;
import android.widget.*;

public class AndExamSetting extends Activity {
	RadioGroup FontSize;
	RadioGroup BackType;
	CheckBox DescSide;
	CheckBox OmitChapter;

	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.andexamsetting);
		
		findViewById(R.id.btnsave).setOnClickListener(mClickListener);
		findViewById(R.id.btncancel).setOnClickListener(mClickListener);

		FontSize = (RadioGroup)findViewById(R.id.opt_fontsize);
		BackType = (RadioGroup)findViewById(R.id.opt_backtype);
		DescSide = (CheckBox)findViewById(R.id.opt_descside);
		OmitChapter = (CheckBox)findViewById(R.id.opt_omitchapter);
		
		SharedPreferences pref = getSharedPreferences("AndExam", 0);
		int mFontSize = pref.getInt("mFontSize", 1);
		int mBackType = pref.getInt("mBackType", 0);
		boolean mDescSide = pref.getBoolean("mDescSide", false);
		boolean mOmitChapter = pref.getBoolean("mOmitChapter", false);

		switch (mFontSize) {
		case 0:
			FontSize.check(R.id.opt_fontsize1);
			break;
		case 1:
			FontSize.check(R.id.opt_fontsize2);
			break;
		case 2:
			FontSize.check(R.id.opt_fontsize3);
			break;
		}

		switch (mBackType) {
		case 0:
			BackType.check(R.id.opt_backtype1);
			break;
		case 1:
			BackType.check(R.id.opt_backtype2);
			break;
		}
		
		DescSide.setChecked(mDescSide);
		OmitChapter.setChecked(mOmitChapter);
	}

	View.OnClickListener mClickListener = new View.OnClickListener() {
		public void onClick(View v) {
			switch (v.getId()) {
			case R.id.btnsave:
				int mFontSize = 0;
				switch (FontSize.getCheckedRadioButtonId()) {
				case R.id.opt_fontsize1:
					mFontSize = 0;
					break;
				case R.id.opt_fontsize2:
					mFontSize = 1;
					break;
				case R.id.opt_fontsize3:
					mFontSize = 2;
					break;
				}
				
				int mBackType = 0;
				switch (BackType.getCheckedRadioButtonId()) {
				case R.id.opt_backtype1:
					mBackType = 0;
					break;
				case R.id.opt_backtype2:
					mBackType = 1;
					break;
				}
				
				boolean mDescSide = DescSide.isChecked();
				boolean mOmitChapter = OmitChapter.isChecked();

				SharedPreferences pref = getSharedPreferences("AndExam", 0);
				SharedPreferences.Editor editor = pref.edit();
				editor.putInt("mFontSize", mFontSize);
				editor.putInt("mBackType", mBackType);
				editor.putBoolean("mDescSide", mDescSide);
				editor.putBoolean("mOmitChapter", mOmitChapter);
				editor.commit();
				
				setResult(RESULT_OK, new Intent());
				finish();
				break;
			case R.id.btncancel:
				setResult(RESULT_CANCELED, new Intent());
				finish();
				break;
			}
		}
	};

}
