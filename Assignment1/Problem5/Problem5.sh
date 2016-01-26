#!/bin/bash

./kepcart -2.047428140424190E+01  2.554708143571569E+01 -9.842432174885170E+00 3.596876688751664E-06 8.539012819887652E-04 -1.405277752039909E-04 27777.0 2.0 >> HaleyComet.csv

/Applications/MATLAB_R2015a.app/bin/matlab -nodisplay -nodesktop -r "try; P5Plot.m; end; quit" > /dev/null 2>&1
