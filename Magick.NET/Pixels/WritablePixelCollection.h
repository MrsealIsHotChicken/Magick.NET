//=================================================================================================
// Copyright 2013-2014 Dirk Lemstra <https://magick.codeplex.com/>
//
// Licensed under the ImageMagick License (the "License"); you may not use this file except in 
// compliance with the License. You may obtain a copy of the License at
//
//   http://www.imagemagick.org/script/license.php
//
// Unless required by applicable law or agreed to in writing, software distributed under the
// License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
// express or implied. See the License for the specific language governing permissions and
// limitations under the License.
//=================================================================================================
#pragma once

#include "..\Exceptions\Base\MagickException.h"
#include "Base\PixelBaseCollection.h"

using namespace System::Collections::Generic;

namespace ImageMagick
{
	///=============================================================================================
	///<summary>
	/// Class that can be used to access the individual pixels of an image and modify them.
	///</summary>
	//==============================================================================================
	public ref class WritablePixelCollection sealed : PixelBaseCollection
	{
		//===========================================================================================
	private:
		//===========================================================================================
		Magick::PixelPacket* _Pixels;
		//===========================================================================================
		void SetPixel(int x, int y, array<Magick::Quantum>^ value);
		//===========================================================================================
		template<typename TType>
		int SetPixel(Magick::PixelPacket *pixel, array<TType>^ value, int index);
		//===========================================================================================
		template<typename TType>
		void SetPixels(array<TType>^ values);
		//===========================================================================================
	protected private:
		//===========================================================================================
		property const Magick::PixelPacket* Pixels
		{
			virtual const Magick::PixelPacket* get() override sealed;
		}
		//===========================================================================================
	internal:
		//===========================================================================================
		WritablePixelCollection(Magick::Image* image, int x, int y, int width, int height);
		//===========================================================================================
	public:
		///==========================================================================================
		///<summary>
		/// Changes the value of the specified pixel. Make sure to call Write after modifying all the
		/// pixels to ensure the image is updated.
		///</summary>
		///<param name="pixel">The pixel to set.</param>
		void Set(Pixel^ pixel);
		///==========================================================================================
		///<summary>
		/// Changes the value of the specified pixels. Make sure to call Write after modifying all the
		/// pixels to ensure the image is updated.
		///</summary>
		///<param name="pixels">The pixels to set.</param>
		void Set(IEnumerable<Pixel^>^ pixels);
		///==========================================================================================
		///<summary>
		/// Changes the value of the specified pixel. Make sure to call Write after modifying all the
		/// pixels to ensure the image is updated.
		///</summary>
		///<param name="x">The X coordinate of the pixel.</param>
		///<param name="y">The Y coordinate of the pixel.</param>
		///<param name="value">The value the pixel (RGBA).</param>
		void Set(int x, int y, array<Magick::Quantum>^ value);
#if (MAGICKCORE_QUANTUM_DEPTH > 8)
		///==========================================================================================
		///<summary>
		/// Changes the values of the specified pixels. Make sure to call Write after modifying all the
		/// pixels to ensure the image is updated.
		///</summary>
		///<param name="values">The values of the pixels (RGBA).</param>
		void Set(array<Byte>^ values);
#endif
		///==========================================================================================
		///<summary>
		/// Changes the values of the specified pixels. Make sure to call Write after modifying all the
		/// pixels to ensure the image is updated.
		///</summary>
		///<param name="values">The values of the pixels (RGBA).</param>
		void Set(array<double>^ values);
		///==========================================================================================
		///<summary>
		/// Changes the values of the specified pixels. Make sure to call Write after modifying all the
		/// pixels to ensure the image is updated.
		///</summary>
		///<param name="values">The values of the pixels (RGBA).</param>
		void Set(array<int>^ values);
		///==========================================================================================
		///<summary>
		/// Changes the values of the specified pixels. Make sure to call Write after modifying all the
		/// pixels to ensure the image is updated.
		///</summary>
		///<param name="values">The values of the pixels (RGBA).</param>
		void Set(array<Magick::Quantum>^ values);
		///==========================================================================================
		///<summary>
		/// Changes the values of the specified pixels. Make sure to call Write after modifying all the
		/// pixels to ensure the image is updated.
		///</summary>
		///<param name="values">The values of the pixels (RGBA).</param>
		void Set(array<short>^ values);
		///==========================================================================================
		///<summary>
		/// Writes the pixels to the image.
		///</summary>
		void Write();
		//===========================================================================================
	};
	//==============================================================================================
}