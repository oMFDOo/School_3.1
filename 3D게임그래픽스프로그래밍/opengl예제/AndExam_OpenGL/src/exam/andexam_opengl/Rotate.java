package exam.andexam_opengl;

import java.nio.*;

import javax.microedition.khronos.egl.*;
import javax.microedition.khronos.opengles.*;

import exam.andexam_opengl.Pyramid.*;

import android.app.*;
import android.content.*;
import android.opengl.*;
import android.os.*;
import android.view.*;

public class Rotate extends Activity {
	MySurface mGLSurfaceView;
	float xAngle, yAngle, zAngle;
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		mGLSurfaceView = new MySurface(this);
		mGLSurfaceView.setFocusable(true);
		mGLSurfaceView.setFocusableInTouchMode(true);
		mGLSurfaceView.setRenderer(new Renderer());
		mGLSurfaceView.setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
		setContentView(mGLSurfaceView);
	}

	protected void onResume() {
		super.onResume();
		mGLSurfaceView.onResume();
	}

	protected void onPause() {
		super.onPause();
		mGLSurfaceView.onPause();
	}

	class MySurface extends GLSurfaceView {

		public MySurface(Context context) {
			super(context);
		}
		
		public boolean onKeyDown(int keyCode, KeyEvent event) {
			switch (keyCode) {
			case KeyEvent.KEYCODE_A:
				yAngle += 2;
				break;
			case KeyEvent.KEYCODE_D:
				yAngle -= 2;
				break;
			case KeyEvent.KEYCODE_W:
				xAngle += 2;
				break;
			case KeyEvent.KEYCODE_S:
				xAngle -= 2;
				break;
			case KeyEvent.KEYCODE_Q:
				zAngle += 2;
				break;
			case KeyEvent.KEYCODE_E:
				yAngle -= 2;
				break;
			case KeyEvent.KEYCODE_Z:
				xAngle = yAngle = zAngle = 0;
				break;
			}
			if (keyCode == KeyEvent.KEYCODE_A) {
				yAngle += 2;
			}

			requestRender();
			return super.onKeyDown(keyCode, event);     
		}
		
		public boolean onTouchEvent(MotionEvent event) {
			WindowManager wm = (WindowManager)getSystemService(
					Context.WINDOW_SERVICE);
			Display dis = wm.getDefaultDisplay();
			int mx = (int) (event.getX()/(dis.getWidth()/3));
			int my = (int) (event.getY()/(dis.getHeight()/3));
			int pos = my * 3 + mx;
			
			switch(pos) {
			case 0:
				zAngle += 2;
				break;
			case 1:
				xAngle += 2;
				break;
			case 2:
				zAngle -= 2;
				break;
			case 3:
			case 6:
				yAngle += 2;
				break;
			case 4:
				xAngle = yAngle = zAngle = 0;
				break;
			case 5:
			case 8:
				yAngle -= 2;
				break;
			case 7:
				xAngle -= 2;
				break;
			}
			
			requestRender();
			return super.onTouchEvent(event);
		}
	}
	
	class Renderer implements GLSurfaceView.Renderer {
		PyramidObject pyramid;
		public Renderer() {
			pyramid = new PyramidObject(); 
		}

		public void onSurfaceCreated(GL10 gl, EGLConfig config) {
			gl.glClearColor(0.2f,0.2f,0.2f,1);

			gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
			gl.glEnableClientState(GL10.GL_COLOR_ARRAY);
			gl.glShadeModel(GL10.GL_SMOOTH);
			gl.glEnable(GL10.GL_DEPTH_TEST);
		}

		public void onSurfaceChanged(GL10 gl, int width, int height) {
			gl.glViewport(0, 0, width, height);
		}

		public void onDrawFrame(GL10 gl) {
			gl.glClear(GL10.GL_COLOR_BUFFER_BIT | GL10.GL_DEPTH_BUFFER_BIT);
			
			gl.glMatrixMode(GL10.GL_MODELVIEW);
			gl.glLoadIdentity();
			gl.glRotatef(xAngle, 1, 0, 0);
			gl.glRotatef(yAngle, 0, 1, 0);
			gl.glRotatef(zAngle, 0, 0, 1);
			
			pyramid.draw(gl);
		}
	}

	class PyramidObject {
		float vert[] = {
				0, 0, -0.8f,			// 중앙
				0.5f, 0.5f, 0,			// 우상
				-0.5f, 0.5f, 0,			// 좌상
				-0.5f, -0.5f, 0,		// 좌하
				0.5f, -0.5f, 0,			// 우하
				0.5f, 0.5f, 0,			// 밑면 우상
			};

		// 색상값에 알파도 반드시 필요함.
		float color[] = {
			1,1,1,1,				// 중앙
			0,0,1,1,				// 우상
			1,0,0,1,				// 좌상
			1,1,0,1,				// 좌하
			0,1,0,1,				// 우하
			1,1,1,1,				// 밑면 우상
		};

		byte index[] = {
			3, 2, 5,			// 밑면1
			4, 3, 5,			// 밑면2
			0, 1, 2,			//12시
			0, 2, 3,			// 9시
			0, 3, 4,			// 6시
			0, 4, 1,			// 3시
		};
		FloatBuffer vertbuf;
		FloatBuffer colorbuf;
		ByteBuffer indexbuf;
		
		public FloatBuffer ArrayToBuffer(float[] ar) {
			ByteBuffer bytebuf = ByteBuffer.allocateDirect(ar.length*4);
			bytebuf.order(ByteOrder.nativeOrder());
			FloatBuffer buf = bytebuf.asFloatBuffer();
			buf.put(ar);
			buf.position(0);
			return buf;
		}

		public PyramidObject() {
			vertbuf = ArrayToBuffer(vert);
			colorbuf = ArrayToBuffer(color);
			
			indexbuf = ByteBuffer.allocateDirect(index.length);
			indexbuf.put(index);
			indexbuf.position(0);
		}

		public void draw(GL10 gl) {
			gl.glVertexPointer(3, GL10.GL_FLOAT, 0, vertbuf);
			gl.glColorPointer(4, GL10.GL_FLOAT, 0, colorbuf);
			gl.glDrawElements(GL10.GL_TRIANGLES, index.length, 
					GL10.GL_UNSIGNED_BYTE, indexbuf);
		}
	}
}

