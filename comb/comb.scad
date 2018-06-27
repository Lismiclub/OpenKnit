//create a hook
module hook(length, width, height, thickness, outer) 
{
    cube([length / 3, width + 1, thickness * 2], center = true);
    translate([length / 6 ,-width / 2, - thickness]) {
    cube([length, thickness, thickness * 1.5], center = false);
    translate([length - 2 * thickness, thickness / 2, outer]){
        rotate([90,0,0]){
            difference(){
            cylinder(h=thickness, r = outer, center=true);
            cylinder(h = 2 * thickness , r = outer - (thickness * 1.5), center = true);
            translate([-3* outer,0,0]) {
                cube([6* outer, 6 * outer, 6 * outer], center = true);
            }
        }
        }
    }
    }
}


lWidth = 15.8;

union(){
       for(i = [ 0: 1: 10-1]){
           //translate
           translate([0,lWidth * i, 0] ){
               #hook(30, lWidth, 4, 1, 3);
           }
       }
   }