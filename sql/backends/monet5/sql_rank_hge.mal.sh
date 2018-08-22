# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0.  If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#
# Copyright 1997 - July 2008 CWI, August 2008 - 2018 MonetDB B.V.

sed '/^$/q' $0			# copy copyright from this file

cat <<EOF
# This file was generated by using the script ${0##*/}.

module sql;

EOF

	cat <<EOF
pattern sql.ntile(b:bat[:any_1], n:hge, p:any_2, o:any_3) :hge
address SQLntile
comment "return the groups divided as equally as possible";

pattern batsql.ntile(b:bat[:any_1], n:hge, p:any_2, o:any_3) :bat[:hge]
address SQLntile
comment "return the groups divided as equally as possible";

EOF

for tp1 in 1:bte 2:sht 4:int 8:lng 16:hge; do
    for tp2 in 16:hge; do
	if [ ${tp1%:*} -le ${tp2%:*} -o ${tp1#*:} = ${tp2#*:} ]; then
	    cat <<EOF
pattern sql.sum(b:${tp1#*:}, p:bit, o:bit, unit:int, s:int, e:int, excl:int) :${tp2#*:}
address SQLscalarsum
comment "return the sum of groups";

pattern batsql.sum(b:bat[:${tp1#*:}], p:any_1, o:any_2, unit:int, s:int, e:int, exl:int) :bat[:${tp2#*:}]
address SQLvectorsum_${tp2#*:}
comment "return the sum of groups";

pattern sql.prod(b:${tp1#*:}, p:bit, o:bit, unit:int, s:int, e:int, excl:int) :${tp2#*:}
address SQLscalarprod
comment "return the product of groups";

pattern batsql.prod(b:bat[:${tp1#*:}], p:any_1, o:any_2, unit:int, s:int, e:int, exl:int) :bat[:${tp2#*:}]
address SQLvectorprod_${tp2#*:}
comment "return the product of groups";

EOF
	fi
    done
done

	cat <<EOF
pattern sql.avg(b:hge, p:bit, o:bit, unit:int, s:int, e:int, excl:int) :dbl
address SQLavg
comment "return the average of groups";

pattern batsql.avg(b:bat[:hge], p:any_1, o:any_2, unit:int, s:int, e:int, exl:int) :bat[:dbl]
address SQLavg
comment "return the average of groups";

EOF
