l = 16;
e = 0.16;
g = 3;

module a(i,j,k) { translate([i*l+e,j*l+e,k*l+e]) cube([l-2*e,l-2*e,l-2*e]); }
module bx(i,j,k) { translate([i*l-2*e,j*l+e,k*l+e]) cube([4*e,l-2*e,l-2*e]); }
module by(i,j,k) { translate([i*l+e,j*l-2*e,k*l+e]) cube([l-2*e,4*e,l-2*e]); }
module bz(i,j,k) { translate([i*l+e,j*l+e,k*l-2*e]) cube([l-2*e,l-2*e,4*e]); }
module cx(i,j,k) { translate([i*l+e,j*l-2*e,k*l-2*e]) cube([l-2*e,4*e,4*e]); }
module cy(i,j,k) { translate([i*l-2*e,j*l+e,k*l-2*e]) cube([4*e,l-2*e,4*e]); }
module cz(i,j,k) { translate([i*l-2*e,j*l-2*e,k*l+e]) cube([4*e,4*e,l-2*e]); }
module d(i,j,k) { translate([i*l-2*e,j*l-2*e,k*l-2*e]) cube([4*e,4*e,4*e]); }

module p() {
  a(0,3,0);
  by(0,3,0);
  a(4,3,0);
  by(4,3,0);
  a(0,2,0);
  by(0,2,0);
  a(2,2,0);
  a(3,2,0);
  bx(3,2,0);
  by(3,2,0);
  a(4,2,0);
  bx(4,2,0);
  cz(4,2,0);
  by(4,2,0);
  a(0,1,0);
  by(0,1,0);
  a(3,1,0);
  a(4,1,0);
  bx(4,1,0);
  a(0,0,0);
  a(0,3,1);
  bz(0,3,1);
  a(4,3,1);
  by(4,3,1);
  cx(4,3,1);
  bz(4,3,1);
  a(2,2,1);
  bz(2,2,1);
  a(4,2,1);
  bz(4,2,1);
  a(0,1,1);
  by(0,1,1);
  cx(0,1,1);
  bz(0,1,1);
  a(0,0,1);
  bz(0,0,1);
  a(0,3,2);
  bz(0,3,2);
  a(4,3,2);
  bz(4,3,2);
  a(2,2,2);
  by(2,2,2);
  bz(2,2,2);
  a(0,1,2);
  by(0,1,2);
  cx(0,1,2);
  bz(0,1,2);
  a(1,1,2);
  bx(1,1,2);
  a(2,1,2);
  bx(2,1,2);
  a(0,0,2);
  bz(0,0,2);
  a(0,3,3);
  by(0,3,3);
  bz(0,3,3);
  a(4,3,3);
  bz(4,3,3);
  a(0,2,3);
  by(0,2,3);
  a(0,1,3);
  by(0,1,3);
  cx(0,1,3);
  bz(0,1,3);
  a(1,1,3);
  bx(1,1,3);
  cy(1,1,3);
  bz(1,1,3);
  a(0,0,3);
  bz(0,0,3);
}
p();
