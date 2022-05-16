# Bullet Debug Drawer
This simple class can be used to render debug informations about bullet physics world.
It renders bounding boxes in wireframe mode.

## Usage

This library uses glad for loading OpenGL functions, it can be replaced in `BulletDebugDrawer.cpp:6`

Simply include `BulletDebugDrawer.hpp` and then :

```cpp
BulletDebugDrawer m_debugDrawer;
btDynamicsWorld *m_world; // or any derived class

in_your_init_function() {
	...
	m_debugDrawer.gl3_device_create();
	m_debugDrawer.setDebugMode(btIDebugDraw::DBG_DrawWireframe);
	m_world->setDebugDrawer(&m_debugDrawer);
	...
}

in_your_render_function() {
	...
	m_world->debugDrawWorld();
	m_debugDrawer.gl3_device_render(matrix);
}
in_your_cleanup_function() {
	...
	m_debugDrawer.gl3_device_destroy();
	...
}
```

## License

This software is licensed under MIT (see : [LICENSE.txt](https://github.com/Polybot-Game/BulletDebugDrawer/blob/master/LICENSE.txt)).