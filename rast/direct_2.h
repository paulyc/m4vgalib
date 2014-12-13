#ifndef VGA_RAST_DIRECT_2_H
#define VGA_RAST_DIRECT_2_H

#include "vga/rasterizer.h"

namespace vga {
namespace rast {

/*
 * A direct-color rasterizer that multiplies pixels by 2 on both axes, for
 * an overall 4x multiplication factor.  For example, this turns an 800x600
 * output timing mode into a 400x300 chunky graphics mode.
 */
class Direct_2 : public Rasterizer {
public:
  Direct_2(unsigned width, unsigned height, unsigned top_line = 0);
  ~Direct_2();

  virtual LineShape rasterize(unsigned, Pixel *) override;

  void flip();
  void flip_now();

  unsigned get_width() const { return _width; }
  unsigned get_height() const { return _height; }
  unsigned char *get_fg_buffer() const { return _fb[_page1]; }
  unsigned char *get_bg_buffer() const { return _fb[!_page1]; }

private:
  unsigned _width;
  unsigned _height;
  unsigned _top_line;
  bool _page1;
  unsigned char *_fb[2];
};

}  // namespace rast
}  // namespace vga

#endif  // VGA_RAST_DIRECT_2_H