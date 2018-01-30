{
  "targets": [
    {
      "target_name": "kpathsea",
      "sources": [
        "src/kpathsea.cc",
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
      ],
      "link_settings": {
        "libraries": [
          "-lkpathsea",
        ],
      },
    },
  ],
}