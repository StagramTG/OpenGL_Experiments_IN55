#pragma once

#include "Camera.h"

#include <iostream>

namespace mjt
{
	class PerspectiveCamera: public Camera
	{
	private:

	public:
		PerspectiveCamera(CameraSettings settings);
		~PerspectiveCamera();

		void update() override;
	};
}
