#!/usr/bin/env python3

import argparse
import struct

def combine_bin(options):
    with open(options.pa, 'rb') as f:
        pa_content = f.read()
        f.close()

    with open(options.pb, 'rb') as f:
        pb_content = f.read()
        f.close()

    with open(options.combin, 'wb') as f:

        pa_length = len(pa_content)
        pb_length = len(pb_content)
        pa_offset = 0
        pb_offset = 0x40000

        print("PA Offset: 0x%x" %(pa_offset))
        print("PA Length: 0x%x" %pa_length)
        fill_byte = struct.pack('B',0xFF)
        print("Fill with 0xFF")
        print("PB Offset: 0x%x" %pb_offset)
        print("PB Length: 0x%x" %pb_length)

        f.seek(pa_offset, 0)
        f.write(pa_content)

        offset = f.tell()
        while offset < pb_offset:
            f.write(fill_byte)
            offset = f.tell()

        f.seek(pb_offset, 0)
        f.write(pb_content)

        f.close()

def parse_options():
    desc = ('SmartSwitch-Gen3 Combine'
            '\n\n'
            'A script used to SmartSwitch-Gen3 combined BIN for Production'
            '\n'
            'firmwares of partition A User and partition B Test together.'
            )

    parser = argparse.ArgumentParser(
        description=desc,
        epilog='Note: Python 3 required.',
        formatter_class=argparse.RawTextHelpFormatter,
        conflict_handler='resolve')

    parser.add_argument('--pa', dest='pa',
                        action='store',
                        required=True,
                        help='Specify path of the firmware of partition A.')

    parser.add_argument('--pb', dest='pb',
                        action='store',
                        required=True,
                        help='Specify path of the firmware of partition B.')

    parser.add_argument('--combin', dest='combin',
                        action='store',
                        required=True,
                        help='Specify name of generated OTA package.')

    return parser.parse_args()


if __name__ == '__main__':
    combine_bin(parse_options())
