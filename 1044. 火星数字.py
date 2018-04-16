import sys
maps = { 0 : [ 'tret' , 'tret' ], 1 : [ 'jan' , 'tam' ] , 2 : [ 'feb' , 'hel'],
         3 : [ 'mar' , 'maa' ] , 4 : [ 'apr' , 'huh' ] , 5 : [ 'may' , 'tou' ],
         6 : [ 'jun' , 'kes' ] , 7 : [ 'jly' , 'hei' ] , 8 : [ 'aug' , 'elo' ],
         9 : [ 'sep' , 'syy' ] ,10 : [ 'oct' , 'lok' ] ,11 : [ 'nov' , 'mer' ],
         12: [ 'dec' , 'jou'] }
remaps = { 'tret' : 0 , 'jan' : 1 , 'feb' : 2 , 'mar' : 3 , 'apr' : 4 , 'may': 5
          ,'jun' : 6 , 'jly' : 7 , 'aug' : 8 , 'sep' : 9 , 'oct' : 10 , 'nov':11
          ,'dec' :12 , 'tam' : 13, 'hel' : 26, 'maa' : 39, 'huh' : 52, 'tou' :65
          ,'kes' :78 , 'hei' : 91, 'elo' :104, 'syy' :117, 'lok' :130,'mer' :143
          ,'jou' : 156 }
N = int( sys.stdin.readline() )
for i in range( N ) :
    num = sys.stdin.readline().strip()
    if num[ 0 ].isdigit() :
        num = int( num )
        divide = int( num / 13 )
        if divide :
            if num % 13 :
                print( maps[ divide ][ 1 ] , maps[ num % 13 ][ 0 ] )
            else :
                print( maps[ divide ][ 1 ] )
        else :
            print( maps[ num % 13 ][ 0 ] )
    else :
        L = num.split()
        if len( L ) == 1 :
            print( remaps[ L[ 0 ] ] )
        else :
            print( remaps[ L[ 0 ] ] + remaps[ L [ 1 ] ] )
