#ifndef BaseComponent_h
#define BaseComponent_h



#include <stdio.h>


class BaseComponent {
public:
	virtual void Awake() {}
	virtual void Start() {}
	virtual void Update() {}
	virtual void LateUpdate() {}
	
};

#endif