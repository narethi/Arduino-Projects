﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EpaperUI
{
    public interface IApplicationController
    {
        void SetMode(string mode);
        void EstablishArduinoConnection();
    }
}
