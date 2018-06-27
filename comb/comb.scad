cube([10,16.4,2], center = true);
translate([5,-8.2,-1]) {
    cube([30, 1, 1.5], center = false);
    translate([28,0.5,3]){
        rotate([90,0,0]){
            difference(){
            cylinder(h=1, r=3, center=true);
            cylinder(h=2, r=1.5, center = true);
            translate([-5,0,0]) {
                cube([10,10,10], center = true);
            }
        }
        }
    }
}