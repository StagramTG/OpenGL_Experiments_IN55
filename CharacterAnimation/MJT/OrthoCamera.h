#pragma once

#include "Camera.h"

namespace mjt
{
	class OrthoCamera: public Camera
	{
	private:

	public:
		OrthoCamera(CameraSettings settings);
		~OrthoCamera();

		virtual void update() override;
	};
}