#concatenating both variables
get_initial_values=$(echo "$FT_NBR1 + $FT_NBR2")
#replacing FT_NBR1 values
replace_nbr1=$(echo "$get_initial_values" | sed -e "s/'/0/g" -e 's/\\/1/g' -e 's/\"/2/g' -e 's/\?/3/g' -e 's/\!/4/g')
#replacing FT_NBR2 values
replace_nbr2=$(echo "$replace_nbr1" | sed -e 's/m/0/g' -e 's/r/1/g' -e 's/d/2/g' -e 's/o/3/g' -e 's/c/4/g')
#setting input and output base values
set_bc_values="ibase=5; obase=23; $replace_nbr2"
#calculating result
calculate_value=$(echo "$set_bc_values" | bc)
#converting result into text
convert_result=$(echo "$calculate_value" | tr '0123456789ABC' 'gtaio luSnemf')
#printing final result
echo "$convert_result"
