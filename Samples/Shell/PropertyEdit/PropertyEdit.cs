//Copyright (c) Microsoft Corporation.  All rights reserved.

using System;
using System.Linq;
using Microsoft.WindowsAPICodePack.Shell;
using System.Collections.Generic;

namespace Microsoft.WindowsAPICodePack.Shell.Samples
{
    class PropertyEdit
    {
        static void Main(string[] args)
        {
            PropertyEdit app = new PropertyEdit();
            app.DoAction(args);
        }

        void DoAction(string [] args)
        {
            if (args.Length == 0 || args[0].Contains("?"))
            {
                Usage();
                return;
            }

         
            if (args[0].Equals("-get", StringComparison.InvariantCultureIgnoreCase))
            {
                string propertyName = args[1];
                string fileName = args[2];
                IProperty prop = ShellFileSystemObject.FromPath(fileName).Properties[propertyName];

                DisplayPropertyValue(prop);

            } 
            else if (args[0].Equals("-set", StringComparison.InvariantCultureIgnoreCase))
            {
                string propertyName = args[1];
                string value = args[2];
                string fileName = args[3];


                IProperty prop = ShellFileSystemObject.FromPath(fileName).Properties[propertyName];
                SetPropertyValue(value, prop);

            } 
            else if (args[0].Equals("-info", StringComparison.InvariantCultureIgnoreCase))
            {
                string propertyName = args[1];
                string fileName = args[2];

                IProperty prop = ShellFileSystemObject.FromPath(fileName).Properties[propertyName];

                ShowPropertyInfo(propertyName, prop);

            }
            else if (args[0].Equals("-enum", StringComparison.InvariantCultureIgnoreCase))
            {
                string fileName = args[1];
                string filter = null;
                if (args.Length > 2)
                {
                    filter = args[1];
                    fileName = args[2];
                }
                EnumProperties(fileName, filter);

            }
            else
            {
                Usage();
                return;
            }
        }

        private static void DisplayPropertyValue(IProperty prop)
        {
            string value = string.Empty;
            value = prop.ValueAsObject == null ? "" : prop.FormatForDisplay(
                    PropertyDescriptionFormat.Default);

            Console.WriteLine("{0} = {1}", prop.CanonicalName, value);
        }

        private static void EnumProperties(string fileName, string filter)
        {
            PropertyCollection collection = new PropertyCollection(fileName);


            var properties = collection
                 .Where(
                     prop => prop.CanonicalName != null &&
                     (filter == null ? true : prop.CanonicalName.StartsWith(filter, StringComparison.CurrentCultureIgnoreCase)))
                 .ToArray();

            
            Array.ForEach(
                properties, 
                p=> 
                {
                    DisplayPropertyValue(p);
                });
        }

        private static void ShowPropertyInfo(string propertyName, IProperty prop)
        {
            Console.WriteLine("\nProperty {0}", propertyName);
            Console.WriteLine("\tPropertyKey: {0}, {1}", prop.PropertyKey.FormatId.ToString("B"), prop.PropertyKey.PropertyId);
            Console.WriteLine("\tLabel:  {0}", prop.Description.DisplayName);
            Console.WriteLine("\tEdit Invitation:  {0}", prop.Description.EditInvitation);
            Console.WriteLine("\tDisplay Type:  {0}", prop.Description.DisplayType);
            Console.WriteLine("\tVar Enum Type:  {0}", prop.Description.VarEnumType);
            Console.WriteLine("\tValue Type:  {0}", prop.Description.ValueType);
            Console.WriteLine("\tDefault Column Width:  {0}", prop.Description.DefaultColumWidth);
            Console.WriteLine("\tAggregation Type:  {0}", prop.Description.AggregationTypes);
            Console.WriteLine("\tHas Multiple Values:  {0}", prop.Description.HasMultipleValues);
            Console.WriteLine("\tIs Group:  {0}", prop.Description.IsGroup);
            Console.WriteLine("\tIs Innate:  {0}", prop.Description.IsInnate);
            Console.WriteLine("\tIs Queryable:  {0}", prop.Description.IsQueryable);
            Console.WriteLine("\tIs Viewable:  {0}", prop.Description.IsViewable);
            Console.WriteLine("\tIs SystemProperty:  {0}", prop.Description.IsSystemProperty);
        }

        private static void SetPropertyValue(string value, IProperty prop)
        {
            if (prop.ValueType == typeof(string[]))
            {
                string [] values = value.Split(new char[] { ';' }, StringSplitOptions.RemoveEmptyEntries);
                (prop as Property<string[]>).Value = values;
            }
            if (prop.ValueType == typeof(string))
            {
                (prop as Property<string>).Value = value;
            }
            else if (prop.ValueType == typeof(ushort?))
            {
                (prop as Property<ushort?>).Value = ushort.Parse(value);
            }
            else if (prop.ValueType == typeof(short?))
            {
                (prop as Property<short?>).Value = short.Parse(value);
            }
            else if (prop.ValueType == typeof(uint?))
            {
                (prop as Property<uint?>).Value = uint.Parse(value);
            }
            else if (prop.ValueType == typeof(int?))
            {
                (prop as Property<int?>).Value = int.Parse(value);
            }
            else if (prop.ValueType == typeof(ulong?))
            {
                (prop as Property<ulong?>).Value = ulong.Parse(value);
            }
            else if (prop.ValueType == typeof(long?))
            {
                (prop as Property<long?>).Value = long.Parse(value);
            }
            else if (prop.ValueType == typeof(DateTime?))
            {
                (prop as Property<DateTime?>).Value = DateTime.Parse(value);
            }
            else if (prop.ValueType == typeof(double?))
            {
                (prop as Property<double?>).Value = double.Parse(value);
            }
        }

        private void Usage()
        {
            Console.WriteLine("Usage: PropertyEdit.exe <OPTIONS> Filename ");
            Console.WriteLine("");
            Console.WriteLine("OPTIONS:");
            Console.WriteLine(" -get <PropertyName>   Get the value for the property defined");
            Console.WriteLine("                       by its Canonical Name in <propertyName>");
            Console.WriteLine(" -set <PropertyName>   Set the value for the property defined");
            Console.WriteLine("      <PropertyValue>	 by <PropertyName> with value <PropertyValue>");
            Console.WriteLine(" -enum  [Filter]  Enumerate all the properties for this file.");
            Console.WriteLine("                  filtering (starting with) Filter value.");
            Console.WriteLine(" -info <PropertyName>  Get schema information on property for this file.");
            Console.WriteLine("");
            Console.WriteLine("Examples:");
            Console.WriteLine("PropertyEdit -get System.Author foo.jpg");
            Console.WriteLine("PropertyEdit -set System.Author \"Jane Smith;John Smith\" foo.docx");
            Console.WriteLine("PropertyEdit -set System.Photo.MeteringMode 2 foo.jpg");
            Console.WriteLine("PropertyEdit -set System.Photo.DateTaken \"3/11/2009 12:03:02\" foo.jpg");
            Console.WriteLine("PropertyEdit -enum foo.jpg");
            Console.WriteLine("PropertyEdit -enum System.Photo foo.jpg");
            Console.WriteLine("PropertyEdit -info System.Author foo.docx");
        }

        
    }
}
