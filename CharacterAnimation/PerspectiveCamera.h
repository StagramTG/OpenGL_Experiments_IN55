#pragma once

#include "Camera.h"

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
