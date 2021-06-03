package exam.andexam_opengl;

import java.nio.*;

import javax.microedition.khronos.egl.*;
import javax.microedition.khronos.opengles.*;

import android.app.*;
import android.opengl.*;
import android.os.*;

public class Triangle extends Activity {
	GLSurfaceView mGLSurfaceView;
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		mGLSurfaceView = new GLSurfaceView(this);
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
	
	class Renderer implements GLSurfaceView.Renderer {
		public Renderer() {
		}

		public void onSurfaceCreated(GL10 gl, EGLConfig config) {
			gl.glClearColor(0.2f,0.2f,0.2f,1);
			gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
		}

		public void onSurfaceChanged(GL10 gl, int width, int height) {
			gl.glViewport(0, 0, width, height);
		}

		public void onDrawFrame(GL10 gl) {
			gl.glClear(GL10.GL_COLOR_BUFFER_BIT);
			gl.glColor4f(1,1,0,1);

			float vert[] = {0, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f };
			ByteBuffer bytebuf = ByteBuffer.allocateDirect(vert.length*4);
			bytebuf.order(ByteOrder.nativeOrder());
			FloatBuffer vertbuf = bytebuf.asFloatBuffer();
			vertbuf.put(vert);
			vertbuf.position(0);
			
			gl.glVertexPointer(2, GL10.GL_FLOAT, 0, vertbuf);
			gl.glDrawArrays(GL10.GL_TRIANGLES, 0, 3);
		}
	}
}

