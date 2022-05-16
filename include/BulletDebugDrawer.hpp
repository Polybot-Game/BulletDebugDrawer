#ifndef BULLET_DEBUG_DRAWER_H
#define BULLET_DEBUG_DRAWER_H

/* USAGE :
 * You may want to replace `#include <glad/gl.h>` in BulletDebugDrawer.cpp:6 by another loader
 *
 *
 *
 * BulletDebugDrawer m_debugDrawer;
 * btDynamicsWorld *m_world; (or any derived class)
 * 
 * in_your_init_function() {
 *		...
 * 		m_debugDrawer.gl3_device_create();
 *		m_debugDrawer.setDebugMode(btIDebugDraw::DBG_DrawWireframe);
 *		m_world->setDebugDrawer(&m_debugDrawer);
 * 		...
 * }
 * 
 *
 * in_your_render_function() {
 * 		...
 *		m_world->debugDrawWorld();
 *		m_debugDrawer.gl3_device_render(matrix);
 * }
 *
 *
 * in_your_cleanup_function() {
 *		...
 * 		m_debugDrawer.gl3_device_destroy();
 * 		...
 * }
 */

#include <bullet/LinearMath/btIDebugDraw.h>
#include <vector>

class BulletDebugDrawer : public btIDebugDraw {
private:
	int m_debugMode;

	std::vector<float> m_lines;

public:
	BulletDebugDrawer();

	virtual void drawLine(const btVector3& from,const btVector3& to,const btVector3& color);

	virtual void reportErrorWarning(const char* warningString);

	virtual void setDebugMode(int debugMode);

	virtual int getDebugMode(void) const;

	virtual void drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color) {

	}

	virtual void draw3dText(const btVector3& location, const char* textString) {

	}

	/* 
	 * Create shaders and buffer objects that are used for the drawer.
	 */
	void gl3_device_create(void);

	/*
	 * It renders a list of lines from `m_lines`
	 *
	 * Params :
	 * const float*			matrix			the projection view matrix.
	 */
	void gl3_device_render(const float *matrix);

	/*
	 * Delete shader program and buffers.
	 */
	void gl3_device_destroy(void);

};
#endif
