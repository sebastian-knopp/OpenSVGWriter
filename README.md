# OpenSVGWriter
Provides a lightweight C++ class to write simplistic SVG files


# Example
The following example was create using Demo.cpp

<svg height="155" width="340">
  <circle cx="23" cy="20" r="6" stroke="black" stroke-width="0" fill="black" />
  <line x1="23" y1="81" x2="23" y2="112"  style="stroke:hotpink;stroke-width:2" />
  <rect x="20" y="128" width="6" height="7"  style="fill:goldenrod; stroke-width:1" />
  <circle cx="38" cy="20" r="6" stroke="black" stroke-width="0" fill="yellowgreen" />
  <line x1="38" y1="81" x2="38" y2="112"  style="stroke:mediumpurple;stroke-width:2" />
  <rect x="35" y="128" width="6" height="7"  style="fill:slategrey; stroke-width:1" />
  <circle cx="54" cy="20" r="6" stroke="black" stroke-width="0" fill="lightskyblue" />
  <line x1="54" y1="81" x2="54" y2="112"  style="stroke:goldenrod;stroke-width:2" />
  <rect x="50" y="128" width="6" height="7"  style="fill:gold; stroke-width:1" />
  <circle cx="69" cy="20" r="6" stroke="black" stroke-width="0" fill="hotpink" />
  <line x1="69" y1="81" x2="69" y2="112"  style="stroke:slategrey;stroke-width:2" />
  <rect x="66" y="128" width="6" height="7"  style="fill:red; stroke-width:1" />
  <circle cx="84" cy="20" r="6" stroke="black" stroke-width="0" fill="mediumpurple" />
  <line x1="84" y1="81" x2="84" y2="112"  style="stroke:gold;stroke-width:2" />
  <rect x="81" y="128" width="6" height="7"  style="fill:black; stroke-width:1" />
  <circle cx="100" cy="20" r="6" stroke="black" stroke-width="0" fill="goldenrod" />
  <line x1="100" y1="81" x2="100" y2="112"  style="stroke:red;stroke-width:2" />
  <rect x="97" y="128" width="6" height="7"  style="fill:yellowgreen; stroke-width:1" />
  <circle cx="115" cy="20" r="6" stroke="black" stroke-width="0" fill="slategrey" />
  <line x1="115" y1="81" x2="115" y2="112"  style="stroke:black;stroke-width:2" />
  <rect x="112" y="128" width="6" height="7"  style="fill:lightskyblue; stroke-width:1" />
  <circle cx="131" cy="20" r="6" stroke="black" stroke-width="0" fill="gold" />
  <line x1="131" y1="81" x2="131" y2="112"  style="stroke:yellowgreen;stroke-width:2" />
  <rect x="128" y="128" width="6" height="7"  style="fill:hotpink; stroke-width:1" />
  <circle cx="146" cy="20" r="6" stroke="black" stroke-width="0" fill="red" />
  <line x1="146" y1="81" x2="146" y2="112"  style="stroke:lightskyblue;stroke-width:2" />
  <rect x="143" y="128" width="6" height="7"  style="fill:mediumpurple; stroke-width:1" />
  <circle cx="162" cy="20" r="6" stroke="black" stroke-width="0" fill="black" />
  <line x1="162" y1="81" x2="162" y2="112"  style="stroke:hotpink;stroke-width:2" />
  <rect x="159" y="128" width="6" height="7"  style="fill:goldenrod; stroke-width:1" />
  <circle cx="177" cy="20" r="6" stroke="black" stroke-width="0" fill="yellowgreen" />
  <line x1="177" y1="81" x2="177" y2="112"  style="stroke:mediumpurple;stroke-width:2" />
  <rect x="174" y="128" width="6" height="7"  style="fill:slategrey; stroke-width:1" />
  <circle cx="193" cy="20" r="6" stroke="black" stroke-width="0" fill="lightskyblue" />
  <line x1="193" y1="81" x2="193" y2="112"  style="stroke:goldenrod;stroke-width:2" />
  <rect x="190" y="128" width="6" height="7"  style="fill:gold; stroke-width:1" />
  <circle cx="208" cy="20" r="6" stroke="black" stroke-width="0" fill="hotpink" />
  <line x1="208" y1="81" x2="208" y2="112"  style="stroke:slategrey;stroke-width:2" />
  <rect x="205" y="128" width="6" height="7"  style="fill:red; stroke-width:1" />
  <circle cx="224" cy="20" r="6" stroke="black" stroke-width="0" fill="mediumpurple" />
  <line x1="224" y1="81" x2="224" y2="112"  style="stroke:gold;stroke-width:2" />
  <rect x="221" y="128" width="6" height="7"  style="fill:black; stroke-width:1" />
  <circle cx="239" cy="20" r="6" stroke="black" stroke-width="0" fill="goldenrod" />
  <line x1="239" y1="81" x2="239" y2="112"  style="stroke:red;stroke-width:2" />
  <rect x="236" y="128" width="6" height="7"  style="fill:yellowgreen; stroke-width:1" />
  <circle cx="255" cy="20" r="6" stroke="black" stroke-width="0" fill="slategrey" />
  <line x1="255" y1="81" x2="255" y2="112"  style="stroke:black;stroke-width:2" />
  <rect x="251" y="128" width="6" height="7"  style="fill:lightskyblue; stroke-width:1" />
  <circle cx="270" cy="20" r="6" stroke="black" stroke-width="0" fill="gold" />
  <line x1="270" y1="81" x2="270" y2="112"  style="stroke:yellowgreen;stroke-width:2" />
  <rect x="267" y="128" width="6" height="7"  style="fill:hotpink; stroke-width:1" />
  <circle cx="285" cy="20" r="6" stroke="black" stroke-width="0" fill="red" />
  <line x1="285" y1="81" x2="285" y2="112"  style="stroke:lightskyblue;stroke-width:2" />
  <rect x="282" y="128" width="6" height="7"  style="fill:mediumpurple; stroke-width:1" />
  <circle cx="301" cy="20" r="6" stroke="black" stroke-width="0" fill="black" />
  <line x1="301" y1="81" x2="301" y2="112"  style="stroke:hotpink;stroke-width:2" />
  <rect x="298" y="128" width="6" height="7"  style="fill:goldenrod; stroke-width:1" />
  <circle cx="316" cy="20" r="6" stroke="black" stroke-width="0" fill="yellowgreen" />
  <line x1="316" y1="81" x2="316" y2="112"  style="stroke:mediumpurple;stroke-width:2" />
  <rect x="313" y="128" width="6" height="7"  style="fill:slategrey; stroke-width:1" />
  <text x="58" y="61" font-size="18" font-family="arial">Welcome to OpenSVGWriter</text>
</svg>
