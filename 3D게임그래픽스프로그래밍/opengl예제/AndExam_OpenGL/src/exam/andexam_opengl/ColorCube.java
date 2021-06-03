package exam.andexam_opengl;

import java.nio.*;

import javax.microedition.khronos.egl.*;
import javax.microedition.khronos.opengles.*;

import android.app.*;
import android.content.*;
import android.opengl.*;
import android.os.*;
import android.view.*;

public class ColorCube extends Activity {
	MySurface mGLSurfaceView;
	float xAngle= 45, yAngle = 45;
	float oldx, oldy;
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		mGLSurfaceView = new MySurface(this);
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
		final static float DRAGSPEED = 5;
		public MySurface(Context context) {
			super(context);
		}
		
		public boolean onTouchEvent(MotionEvent event) {
			float x = event.getX();
	        float y = event.getY();

	        if (event.getAction() == MotionEvent.ACTION_MOVE) {
	        	float dx = (oldx - x)/DRAGSPEED;
	        	float dy = (oldy - y)/DRAGSPEED;
	        
	        	yAngle += dx;
	        	xAngle += dy;
	        	
				requestRender();
	        }

        	oldx = x;
        	oldy = y;

        	return true;
		}
	}

	class Renderer implements GLSurfaceView.Renderer {
		CubeObject cube;
		public Renderer() {
			cube = new CubeObject(); 
		}

		public void onSurfaceCreated(GL10 gl, EGLConfig config) {
			gl.glClearColor(0.2f,0.2f,0.2f,1);
			gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
			gl.glEnableClientState(GL10.GL_COLOR_ARRAY);
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

			cube.draw(gl);
		}
	}
	
	class CubeObject {
		float vert[] = {
				-0.5f, 0.5f, -0.5f,
				0.5f, 0.5f, -0.5f,
				0.5f, -0.5f, -0.5f,
				-0.5f, -0.5f, -0.5f,
				-0.5f, 0.5f, 0.5f,
				0.5f, 0.5f, 0.5f,
				0.5f, -0.5f, 0.5f,
				-0.5f, -0.5f, 0.5f,
			};
		
		float color[] = {
				0,1,1,1,
				1,1,1,1,
				1,1,0,1,
				0,1,0,1,
				0,0,1,1,
				1,0,1,1,
				1,0,0,1,
				0,0,0,1,
			};
		
		byte index[] = {
				0,3,1,	1,3,2,
				1,2,6,	1,6,5,
				0,1,4,	1,5,4,
				4,5,7,	7,5,6,
				0,4,7,	0,7,3,
				3,7,2,	2,7,6,
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

		public CubeObject() {
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

