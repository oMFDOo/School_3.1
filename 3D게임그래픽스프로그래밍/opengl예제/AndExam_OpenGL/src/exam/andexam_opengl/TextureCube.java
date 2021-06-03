package exam.andexam_opengl;

import java.io.*;
import java.nio.*;

import javax.microedition.khronos.egl.*;
import javax.microedition.khronos.opengles.*;

import android.app.*;
import android.content.*;
import android.graphics.*;
import android.opengl.*;
import android.os.*;
import android.view.*;

public class TextureCube extends Activity {
	MySurface mGLSurfaceView;
	float xAngle= 45, yAngle = 45;
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
		float oldx, oldy;
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
			gl.glEnable(GL10.GL_DEPTH_TEST);
			gl.glEnable(GL10.GL_TEXTURE_2D);
			gl.glEnableClientState(GL10.GL_TEXTURE_COORD_ARRAY);

			InputStream stream = getResources().openRawResource(R.drawable.cornpng);
			Bitmap bitmap = BitmapFactory.decodeStream(stream);
			try {
				stream.close();
			} catch (IOException e) { ; }

			int[] textures = new int[1];
			gl.glGenTextures(1, textures, 0);
			gl.glBindTexture(GL10.GL_TEXTURE_2D, textures[0]);
			gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MIN_FILTER, GL10.GL_LINEAR);
			gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MAG_FILTER, GL10.GL_LINEAR);
			GLUtils.texImage2D(GL10.GL_TEXTURE_2D, 0, bitmap, 0);
			bitmap.recycle();
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
				-0.5f, 0.5f, -0.5f,			// 0
				0.5f, 0.5f, -0.5f,
				0.5f, -0.5f, -0.5f,
				-0.5f, -0.5f, -0.5f,
				
				-0.5f, 0.5f, 0.5f,			// 4
				0.5f, 0.5f, 0.5f,
				0.5f, 0.5f, -0.5f,
				-0.5f, 0.5f, -0.5f,

				-0.5f, 0.5f, 0.5f,			// 8
				0.5f, 0.5f, 0.5f,
				0.5f, -0.5f, 0.5f,
				-0.5f, -0.5f, 0.5f,
		
				-0.5f, -0.5f, 0.5f,			// 12
				0.5f, -0.5f, 0.5f,
				0.5f, -0.5f, -0.5f,
				-0.5f, -0.5f, -0.5f,

				0.5f, 0.5f, -0.5f,			// 16
				0.5f, 0.5f, 0.5f,
				0.5f, -0.5f, 0.5f,
				0.5f, -0.5f, -0.5f,

				-0.5f, 0.5f, -0.5f,			// 20
				-0.5f, 0.5f, 0.5f,
				-0.5f, -0.5f, -0.5f,
				-0.5f, -0.5f, 0.5f,
		};
		
		
		float text[] = {
				0,1,1,1,1,0,0,0,
				0,1,1,1,1,0,0,0,
				0,1,1,1,1,0,0,0,
				0,1,1,1,1,0,0,0,
				0,1,1,1,1,0,0,0,
				0,1,1,1,1,0,0,0,
		};
		
		byte index[] = {
				0,3,1,	1,3,2,
				4,7,6,	4,6,5,
				8,11,10,	8,10,9,
				12,14,15,	12,13,14,
				16,18,19,	16,18,17,
				20,23,22,	20,21,23,	
		};
		
		FloatBuffer vertbuf;
		FloatBuffer textbuf;
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
			textbuf = ArrayToBuffer(text);

			indexbuf = ByteBuffer.allocateDirect(index.length);
			indexbuf.put(index);
			indexbuf.position(0);
		}
		
		public void draw(GL10 gl) {
			gl.glVertexPointer(3, GL10.GL_FLOAT, 0, vertbuf);
			gl.glTexCoordPointer(2, GL10.GL_FLOAT, 0, textbuf);
			gl.glDrawElements(GL10.GL_TRIANGLES, index.length, 
					GL10.GL_UNSIGNED_BYTE, indexbuf);
		}
	}
}

