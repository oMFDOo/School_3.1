package exam.andexam_opengl;

import java.nio.*;

import javax.microedition.khronos.egl.*;
import javax.microedition.khronos.opengles.*;

import android.app.*;
import android.content.*;
import android.opengl.*;
import android.os.*;
import android.view.*;

public class Pyramid extends Activity {
	GLSurfaceView mGLSurfaceView;
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		mGLSurfaceView = new GLSurfaceView(this);
		mGLSurfaceView.setRenderer(new Renderer());
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

	class Renderer implements GLSurfaceView.Renderer {
		PyramidObject pyramid;
		public Renderer() {
			pyramid = new PyramidObject(); 
		}

		public void onSurfaceCreated(GL10 gl, EGLConfig config) {
			gl.glClearColor(0.2f,0.2f,0.2f,1);

			gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
			gl.glEnableClientState(GL10.GL_COLOR_ARRAY);
			gl.glShadeModel(GL10.GL_FLAT);
			gl.glEnable(GL10.GL_DEPTH_TEST);
		}

		public void onSurfaceChanged(GL10 gl, int width, int height) {
			gl.glViewport(0, 0, width, height);
		}

		public void onDrawFrame(GL10 gl) {
			gl.glClear(GL10.GL_COLOR_BUFFER_BIT | GL10.GL_DEPTH_BUFFER_BIT);
			
			gl.glRotatef(0.3f, 1, 0, 0);
			gl.glRotatef(1.0f, 0, 1, 0);
			
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

