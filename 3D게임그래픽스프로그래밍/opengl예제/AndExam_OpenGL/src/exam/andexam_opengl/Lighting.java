package exam.andexam_opengl;

import java.nio.*;

import javax.microedition.khronos.egl.*;
import javax.microedition.khronos.opengles.*;

import exam.andexam_opengl.TextureCube.*;

import android.app.*;
import android.content.*;
import android.opengl.*;
import android.os.*;
import android.view.*;

public class Lighting extends Activity {
	MySurface mGLSurfaceView;
	float xAngle, yAngle;
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
		FloatBuffer AmbientBuffer;
		FloatBuffer DiffuseBuffer;
		FloatBuffer lightPosBuffer;

		public Renderer() {
			cube = new CubeObject(); 
		}

		public void onSurfaceCreated(GL10 gl, EGLConfig config) {
			gl.glClearColor(0.2f,0.2f,0.2f,1);

			gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
			gl.glEnableClientState(GL10.GL_NORMAL_ARRAY);
			gl.glShadeModel(GL10.GL_FLAT);
			gl.glEnable(GL10.GL_DEPTH_TEST);

			gl.glEnable(GL10.GL_LIGHTING);
			float[] Ambient = {0.5f, 0.5f, 0.5f, 1.0f};
			float[] Diffuse = {0.5f, 0.5f, 0.5f, 1.0f};
			float[] lightPos = {0.0f, 0.0f, -1.0f, 1.0f};
			ByteBuffer bytebuf = ByteBuffer.allocateDirect(Ambient.length * 4);
			bytebuf.order(ByteOrder.nativeOrder());
			AmbientBuffer = bytebuf.asFloatBuffer();
			AmbientBuffer.put(Ambient);
			AmbientBuffer.position(0);
			
			bytebuf = ByteBuffer.allocateDirect(Diffuse.length * 4);
			bytebuf.order(ByteOrder.nativeOrder());
			DiffuseBuffer = bytebuf.asFloatBuffer();
			DiffuseBuffer.put(Diffuse);
			DiffuseBuffer.position(0);
			
			bytebuf = ByteBuffer.allocateDirect(lightPos.length * 4);
			bytebuf.order(ByteOrder.nativeOrder());
			lightPosBuffer = bytebuf.asFloatBuffer();
			lightPosBuffer.put(lightPos);
			lightPosBuffer.position(0);

			gl.glLightfv(GL10.GL_LIGHT0, GL10.GL_AMBIENT, AmbientBuffer);
			gl.glLightfv(GL10.GL_LIGHT0, GL10.GL_DIFFUSE, DiffuseBuffer);
			gl.glLightfv(GL10.GL_LIGHT0, GL10.GL_POSITION, lightPosBuffer);
			gl.glEnable(GL10.GL_LIGHT0);
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
		
		float normal[] = {
				0.0f, 0.0f, -1.0f,
				0.0f, 0.0f, -1.0f,
				0.0f, 0.0f, -1.0f,
				0.0f, 0.0f, -1.0f,

				0.0f, 1.0f, 0.0f,
				0.0f, 1.0f, 0.0f,
				0.0f, 1.0f, 0.0f,
				0.0f, 1.0f, 0.0f,

				0.0f, 0.0f, 1.0f,
				0.0f, 0.0f, 1.0f,
				0.0f, 0.0f, 1.0f,
				0.0f, 0.0f, 1.0f,

				0.0f, -1.0f, 0.0f,
				0.0f, -1.0f, 0.0f,
				0.0f, -1.0f, 0.0f,
				0.0f, -1.0f, 0.0f,

				1.0f, 0.0f, 0.0f,
				1.0f, 0.0f, 0.0f,
				1.0f, 0.0f, 0.0f,
				1.0f, 0.0f, 0.0f,

				-1.0f, 0.0f, 0.0f,
				-1.0f, 0.0f, 0.0f,
				-1.0f, 0.0f, 0.0f,
				-1.0f, 0.0f, 0.0f,
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
		FloatBuffer normalbuf;
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
			normalbuf = ArrayToBuffer(normal);
			
			indexbuf = ByteBuffer.allocateDirect(index.length);
			indexbuf.put(index);
			indexbuf.position(0);
		}
		
		public void draw(GL10 gl) {
			gl.glVertexPointer(3, GL10.GL_FLOAT, 0, vertbuf);
			gl.glNormalPointer(GL10.GL_FLOAT, 0, normalbuf);
			gl.glDrawElements(GL10.GL_TRIANGLES, index.length, 
					GL10.GL_UNSIGNED_BYTE, indexbuf);
		}
	}
}

