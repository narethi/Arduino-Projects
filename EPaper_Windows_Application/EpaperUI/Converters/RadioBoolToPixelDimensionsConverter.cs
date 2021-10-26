using System;
using System.Globalization;
using System.Windows.Data;

namespace EpaperUI.Converters
{
    public class RadioBoolToPixelDimensionsConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (int.TryParse(parameter.ToString(), out var param) && 
                (int)value == param)
            {
                return true;
            }

            return false;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            return parameter;
        }
    }
}
