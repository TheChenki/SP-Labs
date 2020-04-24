using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// Документацию по шаблону элемента "Пустая страница" см. по адресу https://go.microsoft.com/fwlink/?LinkId=234238

namespace Lab6_UWP
{
    /// <summary>
    /// Пустая страница, которую можно использовать саму по себе или для перехода внутри фрейма.
    /// </summary>
    public sealed partial class Calculator : Page
    {
        public Calculator()
        {
            this.InitializeComponent();
        }

        private void ButtonBase_OnClick(object sender, RoutedEventArgs e)
        {
            double a, b;

            Result.Text = "";

            if (!Double.TryParse(A.Text, out a))
            {
                Result.Text = "Operand A is not number!";
                return;
            }

            if (!Double.TryParse(B.Text, out b))
            {
                Result.Text = "Operand B is not number!";
                return;
            }

            switch (Operations.SelectedIndex)
            {
                case 0: Result.Text = (a + b).ToString(); break;
                case 1: Result.Text = (a - b).ToString(); break;
                case 2: Result.Text = (a * b).ToString(); break;
                case 3: Result.Text = (b == 0 ? "Can't divide by zero" : (a / b).ToString()); break;
                case 4: Result.Text = (Math.Sin(a)).ToString(); break;
                case 5: Result.Text = (Math.Cos(a)).ToString(); break;
                case 6: Result.Text = (Math.Tan(a)).ToString(); break;
                case 7: Result.Text = (a < 0 ? "A can't be less than 0" : (Math.Sqrt(a)).ToString()); break;
                case 8: Result.Text = (Math.Log(a)).ToString(); break;
                case 9: Result.Text = (Math.Pow(a,b)).ToString(); break;
            }
        }
    }
}
