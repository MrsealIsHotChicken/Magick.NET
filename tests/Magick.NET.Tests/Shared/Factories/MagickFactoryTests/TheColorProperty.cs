﻿// Copyright 2013-2020 Dirk Lemstra <https://github.com/dlemstra/Magick.NET/>
//
// Licensed under the ImageMagick License (the "License"); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
//
//   https://www.imagemagick.org/script/license.php
//
// Unless required by applicable law or agreed to in writing, software distributed under the
// License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
// either express or implied. See the License for the specific language governing permissions
// and limitations under the License.

using ImageMagick;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Magick.NET.Tests
{
    public partial class MagickFactoryTests
    {
        [TestClass]
        public class TheColorProperty
        {
            [TestMethod]
            public void ShouldReturnInstance()
            {
                var factory = new MagickFactory();

                Assert.IsNotNull(factory.Color);
                Assert.IsInstanceOfType(factory.Color, typeof(MagickColorFactory));
            }

            [TestMethod]
            public void ShouldReturnTheSameInstance()
            {
                var factory = new MagickFactory();

                var first = factory.Color;
                var second = factory.Color;
                Assert.AreSame(first, second);
            }
        }
    }
}
